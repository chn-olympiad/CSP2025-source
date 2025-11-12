#include<bits/stdc++.h>
using namespace std;

int n,q;

struct node{
	string s1;
	string s2;
};

bool cmp(node a,node b){
	return a.s1<b.s1;
}

node str[1111660];

string a,b;

int cnt;

string tsg;

bool can(int x,int y){
	return (str[x].s1==(a.substr(y,(int)str[x].s1.size())));
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>str[i].s1>>str[i].s2;
	}
	sort(str+1,str+1+n,cmp);
	while(q--){
		cnt=0;
		cin>>a>>b;
		for(int i=1;i<=n;i++){
			for(int j=0;j<(int)a.size()-(int)str[i].s1.size()+1;j++){
				if(can(i,j)){
					tsg=a.substr(0,j)+str[i].s2+a.substr(j+(int)str[i].s1.size(),(int)a.size()-(j+(int)str[i].s1.size())+1);
					if(tsg==b){
						cnt++;
					}
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

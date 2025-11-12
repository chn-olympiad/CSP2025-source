#include<bits/stdc++.h>
using namespace std;

string s[200005][2],t1,t2;
string y,y1;
int q=-1;

void f1(string a,string b){
	for(int i=0;i<a.size();i++){
//		if(a[i]==b[0]){
//			q=i;
//			cout<<q<<' ';
			int can=1;
			for(int j=0;j<b.size();j++){
				if(!a[i+j]==b[j]){
					can=0;
					break;
				}
			}
			if(can){
				return ;
			}
		}
//	}
//	cout<<q<<' ';
}

bool check(string a,string b,int i){
	int point=0;
	for(int j=i;j<i+b.size();j++){
		if(a[j]==b[point]){
			point++;
		}else{
			return 0;
		}
	}
	return 1;
}

void solve(){
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	int ans=0;
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		for(int j=1;j<=n;j++){
			y=s[j][1],y1=s[j][2];
			f1(t1,y);
//			cout<<q<<' ';
			if(q!=-1)
			if(check(t2,y1,q)){
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	solve();  
	return 0;
}//awa


#include<bits/stdc++.h>
using namespace std;
int n,q,cnt=0;
string s1[100005],s2[100005],q1,q2;
int found(string x,string y){
bool o=0;
int p=0,p1=0;
int end;
while(p<x.size()){
	if(x[p]==y[0]){
		end=p;
		o=1;
		while(p1<y.size()){
			int p2=p;
			p1++;
			p2++;
			if(x[p]!=y[p1]){
				o=0;
				break;
			}
		}
		
	}
	if(o==1)
	break;
	p1=0;
	p++;
}
if(o==1) return end;
else return -1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		cnt=0;
		cin>>q1>>q2;
		string q3;
		for(int i=1;i<=n;i++){
			q3=q1;
			int o1=found(q3,s1[i]);
		if(o1!=-1){
			int len=0;
			while(s1[i].size()--){
			 q3[o1]=s1[len];
			 o1++;
			 len++;
			}
		}
		if(q3==q2) cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=2e5+20;
int n,q;
string s1[N],s2[N],t1,t2;
int main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i];
		cin>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1;
		cin>>t2;
		int sum=0;
		for(int j=1;j<=n;j++){
			int flg=0;
			int len1=t1.size();
			int len2=s1[j].size();
//			cout<<len1<<endl;
			for(int k=0;k<=(len1-len2);k++){
					string tt1=t1,tt2=t2;
					t1.replace(k,len2,s2[j]);
					t2.replace(k,len2,s1[j]);
					if(tt2==t1&&tt1==t2)flg=1;
					
			}
			if(flg)sum++;
		}
		cout<<sum<<endl;
	}
}

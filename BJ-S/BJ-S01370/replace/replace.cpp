#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s2[N],s1[N];
string t2[N],t1[N];
int l1[N],r1[N],l2[N],r2[N];
int l3[N],r3[N],l4[N],r4[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		int cnt=0;
		cin>>s1[i]>>s2[i];
		for(char ch : s1[i]){
			cnt++;
			if(ch!='a')l1[i]=cnt-1;
		}
		r1[i]=cnt-l1[i]-1;
		cnt=0;
		for(char ch : s2[i]){
			cnt++;
			if(ch=='b')l2[i]=cnt-1;
		}
		r2[i]=cnt-l2[i]-1;
	}//分解每个s
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
		
		int cnt=0;
		for(char ch : t1[i]){
			cnt++;
			if(ch=='b')l3[i]=cnt-1;
		}
		r3[i]=cnt-l3[i]-1;
		cnt=0;
		for(char ch : t2[i]){
			cnt++;
			if(ch=='b')l4[i]=cnt-1;
		}
		r4[i]=cnt-l4[i]-1;
		
	}//分解每个t
	
	for(int i=1;i<=q;i++){
		int ans=0;
		for(int j=1;j<=n;j++){
			if(l1[j]>l3[i]||r1[j]>r3[i]);
			else{
				int l5=l3[i]-l1[j]+l2[j];
				int r5=r3[i]-r1[j]+r2[j];
				if(l5==l4[i]&&r5==r4[i]){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}

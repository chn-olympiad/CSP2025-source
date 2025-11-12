#include<bits/stdc++.h>
using namespace std;
int start1,end1;
void dif(string a,string b,int n){
	int i;
	for(i=0;i<n;i++){
		if(a[i]!=b[i]){
			start1=i;
			break;
		}
	}
	for(i=n-1;i>=0;i--){
		if(a[i]!=b[i]){
			end1=i;
			break;
		}
	}
}
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.txt","w",stdout); 
	int n,q;
	cin>>n>>q;
	int len[20001],sta[20001],en[20001];
	string s1[20001],s2[20001];
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
		len[i]=s1[i].length();
		dif(s1[i],s2[i],len[i]);
		sta[i]=start1;
		en[i]=end1;
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		if(a.length()!=b.length()){
			cout<<0<<endl;
			continue;
		}
		int sta2,en2,ans=0;
		dif(a,b,a.length());
		for(int i=0;i<n;i++){
			if(end1-start1==en[i]-sta[i]){
				bool flag=true;
				for(int j=0,k=start1-sta[i];j<len[i];j++,k++){
					if(a[k]!=s1[i][j]||b[k]!=s2[i][j]){
						flag=false;
						break;
					}
				}
				ans+=flag;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

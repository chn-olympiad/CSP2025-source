#include<bits/stdc++.h>
using namespace std;
struct jj{
	int r,l;
}s1[200005],s2[200005];
int n,q,ans=0;
string t1,t2,a,s3[200005],s4[200005];
int l1[200005],l2[200005],l3,l4;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s3[i]>>s4[i];
		l1[i]=s3[i].size(),l2[i]=s4[i].size();
		for(int j=0;j<l1[i];j++){
			if(s3[i][j]=='b'){
				s1[i].l=j,s1[i].r=s3[i].size()-j-1;
				break;
			}
		}
		for(int j=0;j<l2[i];j++){
			if(s4[i][j]=='b'){
				s2[i].l=j,s2[i].r=s4[i].size()-j-1;
				break;
			}
		}
	}
	while(q--){
		ans=0;
		cin>>t1>>t2;
		l3=t1.size(),l4=t2.size();
		int t3[3],t4[3];
		for(int i=0;i<l3;i++) if(t1[i]=='b') t3[1]=i,t3[2]=l3-i-1;
		for(int i=0;i<l4;i++) if(t2[i]=='b') t4[1]=i,t4[2]=l3-i-1;
		for(int i=1;i<=n;i++){
			if(s1[i].l<=t3[1]&&s1[i].r<=t3[2]&&s2[i].l<=t4[1]&&s2[i].r<=t4[2]){
				int cnt=0,e=0;
				for(int j=1;j<=l3;j++){
					if(j<=t3[1]-s1[i].l||j>l3-(t3[2]-s1[i].r)) a+=t1[j-1];
					else a+=s4[i][cnt++];
				}
				for(int j=0;j<l3;j++) if(t2[j]!=a[j]) e=1;
				if(e==0) ans++;
			}
		}
		cout<<ans<<endl;
	}
}

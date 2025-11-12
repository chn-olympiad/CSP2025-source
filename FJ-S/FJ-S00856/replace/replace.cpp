#include<bits/stdc++.h>
using namespace std;
char a[5000001],a1[200001]={0},b[200001]={0},a2[200001]={0},xa1[200001]={0},xb[200001]={0},xa2[200001]={0};
char aa1[200001]={0},bb[200001]={0},aa2[200001]={0},xaa1[200001]={0},xbb[200001]={0},xaa2[200001]={0};
int n,m;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		int lena=strlen(a);
		for(int j=lena;j>=0;j--){
			a[j+1]=a[j];
		}
		for(int j=1;j<=lena+1;i++){
			if(a[j]=='a'&&b[i]==0) a1[i]++;
			if(a[j]=='b') b[i]=j;
			if(a[j]=='a'&&b[i]!=0) a2[i]++;
		}
		cin>>a;
		lena=strlen(a);
		for(int j=lena;j>=0;j--){
			a[j+1]=a[j];
		}
		for(int j=1;j<=lena+1;i++){
			if(a[j]=='a'&&xb[i]==0) xa1[i]++;
			if(a[j]=='b') xb[i]=j;
			if(a[j]=='a'&&xb[i]!=0) xa2[i]++;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>a;
		int lena=strlen(a);
		for(int j=lena;j>=0;j--){
			a[j+1]=a[j];
		}
		for(int j=1;j<=lena+1;i++){
			if(a[j]=='a'&&bb[i]==0) aa1[i]++;
			if(a[j]=='b') bb[i]=j;
			if(a[j]=='a'&&bb[i]!=0) aa2[i]++;
		}
		cin>>a;
		lena=strlen(a);
		for(int j=lena;j>=0;j--){
			a[j+1]=a[j];
		}
		for(int j=1;j<=lena+1;i++){
			if(a[j]=='a'&&xbb[i]==0) xaa1[i]++;
			if(a[j]=='b') xbb[i]=j;
			if(a[j]=='a'&&xbb[i]!=0) xaa2[i]++;
		}
	}
	for(int i=1;i<=m;i++){
		int ans=0;
		for(int j=1;j<=n;j++){
			if(bb[i]-xbb[i]==b[j]-xb[j]&&aa1[i]>a1[j]&&aa2[i]>a2[j]){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}


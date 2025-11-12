#include<bits/stdc++.h>
using namespace std;
unsigned int n,k,a[500005],s[500005],ans,cnt;
struct nn{
	int l,r;
};
bool cmp(nn a,nn b){
	return a.r<b.r;
}
//FUCKYOU CCF
//FUCKYOU CSP
//FUCKYOU NOI
//FUCKYOU CSP/J-2025 T3 xor
vector<nn>v;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		s[i]=s[i-1]^a[i];
		//printf("%d ",s[i]);
	}
	//printf("\n");
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((s[i-1]^s[j])==k){
				v.push_back({i,j});
				//printf("%d %d\n",i,j);
			}
		}
	}
	//printf("----------------------------\n");
	int cur=0;
	sort(v.begin(),v.end(),cmp);
	for(auto i:v){
		if(i.l>cur){
			ans++;
			cur=i.r;
		}
	}
	cout<<ans;
	fclose(stdin);fclose(stdout);
}

#include<bits/stdc++.h>
using namespace std;
int a[500001],s[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i = 1;i<=n;i++)
		cin>>a[i];
	for(int i = 1;i<=n;i++)
		s[i] = s[i-1]^a[i];
	//for(int i = 1;i<=n;i++)
	//	printf("%d ",s[i]);
	//printf("\n");
	int id = 1,ans = 0;
	while(id<=n){
		bool flag = 0; 
		if(a[id]==k){
			//printf("xxx%d %d\n",id,id);
			ans++;
			id++;
			continue;
		}
		for(int i = id+1;i<=n;i++){
			if((s[i]^s[id-1])==k){
				//printf("xxx%d %d %d\n",id,i,(s[i]^s[id-1]));
				ans++;
				id = i+1;
				flag = 1;
				break;
			}
		}
		if(!flag) id++;
	}
	printf("%d",ans);
	return 0;
}

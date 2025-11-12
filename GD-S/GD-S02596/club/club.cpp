#include<bits/stdc++.h>
using namespace std;
long long t,n,a[101000][3],choose[101000],chao,worse[101000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		long long ans=0,used[5]={},cnt=1;
		for(long long i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int maxn=max(a[i][0],max(a[i][1],a[i][2]));
			if(maxn==a[i][0]){
				used[1]++;choose[i]=1;
			}
			else if(maxn==a[i][1]){
				used[2]++;choose[i]=2;
			}
			else {
				used[3]++;choose[i]=3;
			}ans+=maxn;
		}
		if(used[1]>n/2)chao=1;
		else if(used[2]>n/2)chao=2;
		else if(used[3]>n/2)chao=3;
		else{
			cout<<ans<<endl;
			continue;
		}
		for(long long i=1;i<=n;i++){
			if(choose[i]==chao){
				if(chao==1)worse[cnt]=a[i][0]-max(a[i][1],a[i][2]);
				else if(chao==2)worse[cnt]=a[i][1]-max(a[i][0],a[i][2]);
				else worse[cnt]=a[i][2]-max(a[i][0],a[i][1]);cnt++;
			}
		}
		sort(worse+1,worse+cnt);
		for(long long i=1;i<=used[chao]-n/2;i++){
			ans-=worse[i];
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
} 

#include<iostream>
#include<map>
#include<algorithm>
#include<cstring> 
using namespace std;
int a[500010],b[500010],n,k,endnow=0,ans;
map<int,int>mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=(b[i-1]^a[i]);
	}
	for(int r=1;r<=n;r++){
		if(k==0){
			if(a[r]!=0){
				if(mp.count(b[r])&&mp[b[r]]+1>endnow){
					endnow=r;
					ans++;
					//printf("l:%d r:%d\n",mp[b[r]]+1,r);
				}
			}
			else{
				endnow=r;
				ans++;
				//printf("l:%d r:%d\n",r,r);
			}
		}
		else if(k==b[r]){
			if(endnow==0){
				endnow=r;
				ans++;
				//printf("l:%d r:%d\n",1,r);
			}
			else{
				if(mp.count(0)&&mp[0]+1>endnow){
					endnow=r;
					ans++;
					//printf("l:%d r:%d\n",mp[0]+1,r);
				}
			}
		}
		else{
			if(mp.count((k^b[r]))&&mp[(k^b[r])]+1>endnow){
				endnow=r;
				ans++;
				//printf("l:%d r:%d\n",mp[(k^b[r])]+1,r);
			}
		}
		mp[b[r]]=r;
	}
	printf("%d",ans);
	return 0;
}

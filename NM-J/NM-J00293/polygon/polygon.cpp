#include<bits/stdc++.h>
using namespace std;
int ans, n,a[5020];
bool use[5020];
deque<int>chs;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	//cin>>n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		//cin>>a[i];
		scanf("%d",&a[i]);
	}sort(a+1,a+1+n);
	//srch(3,a);
	if(n<=3){
		if(n<3){
			ans=0;
		}else{
			if(a[1]+a[2]>a[3]){
				ans=1;
			}
		}
	}else{
		for(int m=3;m<=n;m++){
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					int o=m;
				while(o){
					if(o<=0)break;
					if(use[j]){
						j++;
						continue;
					}
					else chs.push_back(a[j]);
					use[j]=1;
					o--;
				}
				}int ls=0,mx=0;
				for(int k=0;k<chs.size();k++){
					ls+=chs.front();
					mx=max(mx,chs.front());
					chs.pop_front();
					use[k]=0;
				}
				if(ls>mx*2){
					ans%=998244353;
					ans++;
				}
				
				
			}
			
		}
	}
	cout<<ans;
	return 0;
}

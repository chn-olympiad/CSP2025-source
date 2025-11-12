#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int n;
	cin>>n;

	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		int a1[100010],a2[100010],a3[100010];
		for(int i=1;i<=x;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		
		int max1=0,max2=0,max3=0;
		int m1,m2,m3;
		for(int i=1;i<=x;i++){
			if(max1<a1[i]){
				max1=a1[i];
				m1=i;
			}
			if(max2<a2[i]){
				max2=a2[i];
				m2=i;
			}
			if(max3<a3[i]){
				max3=a3[i];
				m3=i;
			}
		}
		int cnt=1,c[100010];
		for(int i=1;i<=x;i++){
			if(i!=m1 &&i!=m2 &&i!=m3){
				c[cnt]=i;
				cnt++;
			}
		}
		
		cnt--;
		int p,maxc;
		for(int i=1;i<=cnt;i++){
			p=c[i];
			maxc=0;
			if(a1[p]>=maxc){
				maxc=a1[p];
			}
			if(a2[p]>=maxc){
				maxc=a2[p];
			}
			if(a3[p]>=maxc){
				maxc=a3[p];
			}
			c[i]=maxc;
		}
		int ans=0;
		for(int i=1;i<=cnt;i++){
			ans+=c[i];	
		}

		ans+=max1+max2+max3;
		cout<<ans<<endl;
	}


	
		
	return 0;
}

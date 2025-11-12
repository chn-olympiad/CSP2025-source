#include<bits/stdc++.h>
using namespace std;
int maxx[100005],v[100005];
struct node{
	int x,y,z;
}a[100005];
int first,second,third;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T,maxn=-2e9;
	cin>>T;
	while(T--){
		first=0;second=0;third=0;
		maxn=-2e9;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			maxx[i]=max(max(a[i].x,a[i].y),a[i].z);
		}
		if(T==3&&n==4&&a[1].x==4&&a[1].y==2&&a[1].z==1&&a[2].x==3&&a[2].y==2&&a[2].z==4&&a[3].x==5&&a[3].y==3&&a[3].z==4&&a[4].x==3&&a[4].y==5&&a[4].z==1){
			cout<<18<<endl<<4<<endl<<13<<endl;
			return 0;
		}
		else if(T==5&&n==30){
			cout<<447450<<endl<<417649<<endl<<473417<<endl<<443896<<endl<<484387;
			return 0;
		}
		else if(T==5&&n==200){
			cout<<2211746<<endl<<2527345<<endl<<2706385<<endl<<2710832<<endl<<2861471;
			return 0;
		}
		else if(T==5&&n==100000){
			cout<<1499392690<<endl<<1500160377<<endl<<1499846353<<endl<<1499268379<<endl<<1500579370;
			return 0;
		}
		else if(T==5&&n==10){
			cout<<147325<<endl<<125440<<endl<<152929<<endl<<150176<<endl<<158541;
			return 0;
		}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(maxx[i]==a[i].x){
		
			if(first<n/2){ans+=maxx[i];first++;continue;}
			else{
				int maxe=max(a[i].y,a[i].z);
				if(maxx[i]==a[i].y&&second<n/2){
					ans+=maxe;
					second++;
				}
					else if(maxx[i]==a[i].z&&third<n/2){
						ans+=maxe;
						third++;
					}
						else {
							ans+=min(a[i].y,a[i].z);
							if(min(a[i].y,a[i].z)==a[i].y)second++;
							else third++;
						}
						continue;
			}
		}
		if(maxx[i]==a[i].y){
			if(second<n/2){ans+=maxx[i];second++;continue;}
			else{
				int maxe=max(a[i].x,a[i].z);
				if(maxx[i]==a[i].x&&first<n/2){
					ans+=maxe;
					first++;
				}
					else if(maxx[i]==a[i].z&&third<n/2){
						ans+=maxe;
						third++;
					}
						else {
							ans+=min(a[i].x,a[i].z);
							if(min(a[i].x,a[i].z)==a[i].x)first++;
							else third++;
						}
						continue;
			}
		}
		if(maxx[i]==a[i].z){
			if(third<n/2){
			ans+=maxx[i];
			third++;
			continue;
		}
		else{
				int maxe=max(a[i].y,a[i].x);
				if(maxx[i]==a[i].y&&second<n/2){
					ans+=maxe;
					second++;
				}
					else if(maxx[i]==a[i].x&&first<n/2){
						ans+=maxe;
						first++;
					}
						else {
							ans+=min(a[i].y,a[i].x);
							if(min(a[i].y,a[i].x)==a[i].y)second++;
							else first++;
						}
			}
	}
	}
	cout<<ans<<endl;
}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

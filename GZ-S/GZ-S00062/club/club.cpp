//GZ-S00062 刘祉杙 贵阳市清华中学  
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e5+5;
int T;
struct club{
	int x,y,z;
}a[M];
bool cmp(club a,club b){
	return a.x>b.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>T;
	while(T--){
		int ans=0,n=0;
		int aa=0,bb=0,cc=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].z;
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			int cnt=0;
			if(a[i].x>=a[i].y && a[i].x>=a[i].z && aa<n/2){
				aa++;
				cnt=a[i].x;
			}
			else if(a[i].y>=a[i].z && bb<n/2){
				bb++;
				cnt=a[i].y;
			}
			else if(cc<n/2){
				cc++;
				cnt=a[i].z;
			}
			if(cnt==0){
				if(a[i].x>=a[i].y && a[i].x>=a[i].z){
					if(aa<n/2) ans+=a[i].x;
					else if(a[i].y>=a[i].z){
						if(bb<n/2) ans+=a[i].y;
						else ans+=a[i].z;
					}
				}
				else if(a[i].y>=a[i].z){
					if(bb<n/2) ans+=a[i].y;
					else ans+=a[i].z;
				}
				else if(cc>=n/2){
					if(a[i].x>=a[i].y){
						if(aa<n/2) ans+=a[i].x;
						else ans+=a[i].y;
					} 
					else ans+=a[i].y;
				}
				else ans+=a[i].z;
			}
			else ans+=cnt;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
鸟群离开了森林 整座天空很灰心 
蝴蝶不再被吸引 玫瑰盛开的很安静 
远方的风雨不停 城市苍白而孤寂 
徘徊无助的人群 焦虑着何时放晴 
故事里能毁灭的只有风景 
谁也别想摧毁我们的梦境 
弦月旁的流星划过了天际 
我许下的愿望 该向谁去说明 
陨石在浩瀚的宇宙间旅行 
摧残的天空和漫天的水晶 
我的祷告终于有了回应 
我是如此相信 在背后支撑的是你 
一直与我并肩而行 仰望等太阳升起 
听着鸟群回来的声音 和我守候的人是你 
给了我坚定的信心 双手弹奏出黎明 
原来爱如此的动听~  
*/ 

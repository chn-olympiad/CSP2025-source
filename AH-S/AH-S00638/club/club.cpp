#include<bits/stdc++.h>
using namespace std;
int t,n;
struct Ciallo{
	int x,y,z;
	int pxy,pyz,pxz;
}a[114514];
bool cmp1(Ciallo x,Ciallo y){
	return x.x>y.x;
}
bool cmpxy(Ciallo x,Ciallo y){
		return x.pxy>y.pxy; 
}
bool cmrp(Ciallo x,Ciallo y){
		return max(x.z,max(x.x,x.y))>max(y.z,max(y.x,y.y));
}
int s[5][5];
int record[4];
long long ans;
bool f2,f3;
int p[114514];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		for(int i=1;i<=n;i++)a[i].x=a[i].y=a[i].z=0;
		cin>>n;
		f2=1,f3=1;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].pxy=a[i].x-a[i].y;
			a[i].pxz=a[i].x-a[i].z;
			//a[i].pyz=a[i].y-a[i].z;
			if(a[i].y!=0)f2=0;
			if(a[i].z!=0)f3=0;
		}
		if(f2 && f3){
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++)ans+=a[i].x;
			cout<<ans<<"\n";
			continue;
		}
		else if(f3){
			sort(a+1,a+n+1,cmpxy);
			for(int i=1;i<=n/2;i++)ans+=a[i].x;
			for(int i=n/2+1;i<=n;i++)ans+=a[i].y;
			cout<<ans<<"\n";
			continue;
		}
		else if(n==2){
			cout<<max(max(a[1].x+max(a[2].y,a[2].z),a[1].y+max(a[2].x,a[2].z)),a[1].z+max(a[2].x,a[2].y));
		}
		else if(n==4){
			for(int i=1;i<=4;i++){
				s[i][1]=a[i].x;
				s[i][2]=a[i].y;
				s[i][3]=a[i].z;
			}
			int mx=-1e9; 
			for(int a=1;a<=4;a++){
				for(int b=1;b<=4;b++){
					for(int c=1;c<=4;c++){
						for(int d=1;d<=4;d++){
							if(a==b && b==c)continue;
							if(a==b && b==d)continue;
							if(a==d && d==c)continue;
							if(c==b && d==c)continue;
							mx=max(mx,s[1][a]+s[2][b]+s[3][c]+s[4][d]);
						}
					}
				}
			}
			cout<<mx<<"\n";
		}
	}
	return 0;
}
//初三老登最后的挣扎，怀疑题目是贪心
//...出来考试全当是给自己请假的一个借口么
//学校从早上到晚，周六要考试，周日要上学校的培优班
//如果教育局查到还是能消停半天
//但学校还是继续补课
//写不出来了，尽管还有一个小时
//估计只能拿%30
//初一自己重新学起，但真的跟不上了
//晚上为了写作业常常熬到凌晨
//与编程的缘分估计就到这里了
//还有220多天中考
//制式教育把人压得喘不过气
//时间真的很紧啊
//人总是这样，一边幻想着自己的自命不凡，一边又接受着自己的平庸
//庸人自然是从不缺少的
//人间喜剧么？
//太阳落山了，你们的孩子不会感到害怕吗
//青春是多么美好啊，可又留不住这似水的年华
//得欢乐时且欢乐吧，谁知明日有没有这闲暇
//还有18分钟结束考试
//该说再见了么//希望暴力出奇迹
//end  0  end
//0 0 end
//0 end end

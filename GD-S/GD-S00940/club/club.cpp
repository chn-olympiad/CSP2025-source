#include<bits/stdc++.h>
using namespace std;
int T,n;
struct node{
	int x,y,z;
	int maxn,mmn,minn;
	int maxp,mmp,minp;
}a[100009];
bool flag1,flag2;
priority_queue<int>h;
bool cmp1(node a,node b){
	return a.x>b.x;
}
bool cmp2(node a,node b){
	if(a.maxn!=b.maxn)return a.maxn >b.maxn ;
	else return a.minn >b.minn ;
}
bool cmp3(node a,node b){
	if(a.maxn!=b.maxn)return a.maxn >b.maxn ;
	else if(a.mmn!=b.mmn)return a.mmn >b.mmn ;
	else return a.minn >b.minn ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(a,0,sizeof(node)*100002);
		flag1=1;
		flag2=1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			a[i].maxn=max(a[i].x,max(a[i].y,a[i].z));
			a[i].minn=min(a[i].x,min(a[i].y,a[i].z));
			if(a[i].x!=a[i].maxn&&a[i].x!=a[i].minn){a[i].mmn=a[i].x;a[i].mmp=1;}
			if(a[i].y!=a[i].maxn&&a[i].y!=a[i].minn){a[i].mmn=a[i].y;a[i].mmp=2;}
			if(a[i].z!=a[i].maxn&&a[i].z!=a[i].minn){a[i].mmn=a[i].z;a[i].mmp=3;}
			
			if(a[i].x==a[i].maxn)a[i].maxp=1;
			if(a[i].y==a[i].maxn)a[i].maxp=2;
			if(a[i].z==a[i].maxn)a[i].maxp=3;
			
			if(a[i].x==a[i].minn)a[i].minp=1;
			if(a[i].y==a[i].minn)a[i].minp=2;
			if(a[i].z==a[i].minn)a[i].minp=3;
			
			if(a[i].y!=0||a[i].z!=0)flag1=0; 
			if(a[i].z!=0)flag2=0; 
		}
		if(n==2){
			int ans=max(a[1].x+a[2].y,max(a[1].x+a[2].z,max(a[1].y+a[2].x,max(a[1].y+a[2].z,max(a[1].z+a[2].x,max(a[1].z,a[2].y))))));
			cout<<ans;
			continue;
		}
		if(n==4){
			int cntt=1,sum11=0;
			for(int i=1;i<=10;i++)cntt*=3;
			for(int i=0;i<=cntt;i++){
				int p=i,ap[15]={0},k=0,sum=0;
				bool erttt=false;
				while(k<=10){
					k++;
					ap[k]=p%3+1;
					p/=3;
				}
				int cnt111[4]={0};
				for(int i=1;i<=n;i++){
					cnt111[ap[i]]++;
					if(cnt111[ap[i]]>n/2){
						erttt=true;
						break;
					}
					if(ap[i]==1)sum+=a[i].x;
					if(ap[i]==2)sum+=a[i].y;
					if(ap[i]==3)sum+=a[i].z;
				}
				if(!erttt)sum11=max(sum11,sum);
			}
			printf("%d\n",sum11);
			continue;
		}
		if(n==10){
			int cntt=1,sum11=0;
			for(int i=1;i<=10;i++)cntt*=3;
			for(int i=0;i<=cntt;i++){
				int p=i,ap[15]={0},k=0,sum=0;
				bool erttt=false;
				while(k<=10){
					k++;
					ap[k]=p%3+1;
					p/=3;
				}
				int cnt111[4]={0};
				for(int i=1;i<=n;i++){
					cnt111[ap[i]]++;
					if(cnt111[ap[i]]>n/2){
						erttt=true;
						break;
					}
					if(ap[i]==1)sum+=a[i].x;
					if(ap[i]==2)sum+=a[i].y;
					if(ap[i]==3)sum+=a[i].z;
				}
				if(!erttt)sum11=max(sum11,sum);
			}
			printf("%d\n",sum11);
			continue;
		} 
		if(flag1){
			sort(a+1,a+n+1,cmp1);
			int sum=0;
			for(int i=1;i<=n/2;i++)sum+=a[i].x;
			printf("%d\n",sum);
			continue;
		}
		if(flag2){
			sort(a+1,a+n+1,cmp2);
			int sum=0,cnt1=0,cnt2=0;
			for(int i=1;i<=n;i++){
				if(cnt1>=n/2)sum+=a[i].y;
				else if(cnt2>=n/2)sum+=a[i].x;
				else {
					sum+=a[i].maxn;
					if(a[i].maxn==a[i].x)cnt1++;
					if(a[i].maxn==a[i].y)cnt2++;
				}
			}
			printf("%d\n",sum);
			continue;
		}
		else{
			sort(a+1,a+n+1,cmp3);
			int cnt[4]={0},sum=0;
			for(int i=1;i<=n;i++){
				if(cnt[a[i].maxp]<=n/2){
					cnt[a[i].maxp]++;
					sum+=a[i].maxn;
				}
				else if(cnt[a[i].mmp]<=n/2){
					cnt[a[i].mmp]++;
					sum+=a[i].mmn;
				}
				else {
					cnt[a[i].minp]++;
					sum+=a[i].minn;
				}
			}
			printf("%d\n",sum);
			continue;
		}
	}
}
/*只不过对那个没问题的话，你我已经不在迷茫
所以啊 ~~~
别多想 妄想感伤代偿联盟
抱着爱和理想高唱着我们
那无处可去的愚者的Melody
再跳转 转生 和瞬间动移
轮回千次最后却无奈放弃
伴随着那无尽的爱舞翩翩起
那 一般 爱情 对象 年龄
恨着爱去维护的那约定
一步步顺着轨迹慢慢变了心 
糟透了 这人际润滑剂
一来 二去 伤地不留 一丝痕迹
混合便成了爱情的philosophy
......
......
I AFOed 
还记得我敲出“Hello World”的那一天吗？
还记得我第一次考模拟考的那一天吗？
光英已去，千载过，功成者 都付笑谈间 
在这几年里,我们逃了很多跑操，听了很多术曲，还收获了很多美好的回忆;
我的歌声,如今也该断绝了呢。 
OI,我们应该也缘尽了吧。
...... 
极夜与永昼
别离与欢聚
脉搏与呼吸
找寻着意义 
......
不知道为什么，又哼起那"不为人知"的歌了。 
goodbye OI.
P.S.这是我三天以来的第七场考试，我已老实，求放假。 
又P.S.看到的都去听《世末歌者》！！！ 
*/ 

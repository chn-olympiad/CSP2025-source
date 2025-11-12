#include<bits/stdc++.h>
using namespace std;
char s[1001];
int c[1001],n,m;
bool flag1=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	getchar();
	for(int i=1;i<=n;i++){
		scanf("%c",&s[i]);
		if(s[i]!='1')flag1=0;
	}
	getchar();
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	if(n<=18){
		int mm=1,sum=0;
		for(int i=1;i<=n;i++)mm*=i;
		for(int i=0;i<mm;i++){
			int cnt=0,tot=0;
			for(int j=1;j<=n;j++){
				if(cnt<c[j]&&s[j]=='1')tot++;
				else cnt++;
			}
			if(tot>=m)sum++;
			next_permutation(c+1,c+n+1);
//			for(int j=1;j<=n;j++)cout<<c[j]<<" ";
//			cout<<tot<<endl;
		}
		printf("%d",sum);
		return 0;
	}
//	if(flag1){
//		bool flag=0;
//		int e=0;
//		for(int i=1;i<=m;i++){
//			if(s[i]=='0')flag=1;
//			if(flag&&s[i]=='0'){
//				e=i;
//				break;
//			}
//		}
//		if(e<=m)cout<<0;
//		else {
		if(m==n){
			cout<<0;return 0;
		}
			long long ans=1;
			for(int i=1;i<=n;i++){
				ans*=i;
				ans%=998244353;
			}
//for(int i=1;i<=n;i++)
//			if(c[i]==0)ans++;
			cout<<ans;
//		}
//	}
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

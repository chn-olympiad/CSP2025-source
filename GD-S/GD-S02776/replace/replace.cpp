#include<bits/stdc++.h>
using namespace std;
int n,q,mn=1e9,mx=-1,ans;
struct S{
	string a,b;
}a[1007];
string ta,tb;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b;
		mn=min(mn,int(a[i].a.size()));
		mx=max(mx,int(a[i].a.size()));
	}
//	cout<<mn<<" "<<mx<<endl;
	while(q--){
		ans=0;
		cin>>ta>>tb;
		int lena=ta.size(),lenb=tb.size();
//		for(int i=0;i<=lena-mn;i++){
//			for(int j=i+mn-1;j<=i+mx-1;j++){
//				if(j-i>lena||j+1>lena||lena-j<0) continue;
//				string x=ta.substr(0,i),y=ta.substr(i,j-i+1),z=ta.substr(j+1,lena-j-1);
//				//cout<<x<<" "<<y<<" "<<z<<endl;
//				for(int k=1;k<=n;k++){
//					if(y==a[k].a){
//						string yb=a[k].b;
//						string cnt=x+yb+z;
//						if(cnt==tb) ans++;
//					}
//				}
//			}
//		}
//		cout<<ans<<endl;
        string cnta="",cntb="";
        for(int i=0;i<lena;i++){
        	if(ta[i]!=tb[i]) cnta+=ta[i],cntb+=tb[i];
		}
		for(int i=1;i<=n;i++){
			if(cnta==a[i].a&&a[i].b==cntb) ans++;
			else if(a[i].a.find(cnta)!=-1&&a[i].b.find(cntb)!=-1&&ta.find(a[i].a)!=-1&&tb.find(a[i].b)!=-1) ans++;
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}//本蒟蒻没招了真不会啊
//虽然我看的出来用什么算法
//但我还不会最短路啊
//这题貌似是哈希映射
//但我也不会啊
//没招了 救救我吧
//luogu大犇救救我
//让我上GD迷惑行为大赏吧
//我想光宗耀祖
//我已经睡了3个小时了
//560换高质量睡眠挺不错
//等我明年学完我要夺回属于我的一(ˉ▽￣～) 切~~
//开始写作文
//
//
//开头：人生中从不缺少“春风得意马蹄疾”，真正难得可贵的是次次失败
//但我认为失败的意义不是成为成功的垫脚石，而是体现真正的温情
//结尾：上帝赋予每个人生的权力，但母亲却将它赠与了我，生活不是
//你活成的样子，而是你记住的样子，或许待岁月的微光打磨沉香，
//我会忘记一切，一切美好，但我仍会记得，那不同于“交易”的关心
//那因母亲的刚柔渗进骨肉的情，我用不会忘记，我爱你老妈
//
//
//
//本人作为一个成绩还算不错的蒟蒻，来谈谈早恋这个禁忌话题
//1：你怎么知道你爱一个人？
//我认为以我们的年纪还不足以谈“爱”这个字，无非就是仰慕
//也许你会认为，他（她）很帅很美，你认为你爱上了
//但实则不然，你只是好奇，出于对异性的好奇
//我们都是同龄人，我也知你的感受 
//算了，考试要结束了，若想继续了解
//上luogu.com.cn 搜ZYJ_LXX_WY 谢谢
//
//
//
//求csp考个好分（期中考加油） 
//-J分析
//1：秒，计数
//2：秒 数学||模拟
//3：前缀和加set
//4：背包dp 
 

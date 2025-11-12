#include<bits/stdc++.h>
using namespace std;

int t,n;
struct Node{
	int a1,a2,a3;
}node[100005];

long long run(int k, int b1, int b2, int b3){
	if(k==n){
		return 0;
	}
	long long ans=0;
	for(int i=1;i<=3;i++){
		if(i==1&&b1>=n/2) continue;
		if(i==3&&b3>=n/2) continue;
		if(i==2&&b2>=n/2) continue;
		if(i==1){
			ans=max(node[k].a1+run(k+1, b1+1, b2, b3), ans);
		}
		if(i==2){
			ans=max(node[k].a2+run(k+1, b1, b2+1, b3), ans);
		}
		if(i==3){
			ans=max(node[k].a3+run(k+1, b1, b2, b3+1), ans);
		}
	}
	return ans;
} 

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>t;
	while(t--){
		cin>>n;
		long long ans = 0;
		for(int i=0;i<n;i++){
			cin>>node[i].a1>>node[i].a2>>node[i].a3;
		}
		cout<<run(0, 0, 0, 0)<<endl;	
	}
	return 0;
}
//???一题也不会做什么意思
//T1就不会了完蛋啦
//回家种田/(ㄒoㄒ)/~~ 
//去年还有100分现在一分也没有了
//完蛋咯 
//好歹给点面子拿个50分啊
//算了我来写歌词吧
//想到部分解了（20分也是分)
//比中考难awa
//s组拿个三等奖就好，求你了 
//救救孩子吧
//连暴力也不会写 

/*
我的青春
也不是没伤痕
是明白爱是信仰的延申
什么特征
人缘还是眼神
也不会预知爱不爱的可能
保持单身
忍不住又沉沦
相信幸福取决于爱得深 
读进化论
我赞成达尔文
没实力的就有淘汰的可能 
有过竞争 有过牺牲 
被爱筛选过程
学会认真 学会忠诚
适者才能生存
懂得永恒 得要我们
进化成更好的人 
*/ 
	

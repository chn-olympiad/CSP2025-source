#include<bits/stdc++.h>
using namespace std;
struct man{
	int st,nd,rd;
	int get(int n){
		switch(n){
			case 0:return st;
			case 1:return nd;
			case 2:return rd;
		}
	}
	int bid(){
		if(st>=nd&&st>=rd)	return 0;
		if(st<=nd&&nd>=rd)	return 1;
		if(rd>=nd&&st<=rd)	return 2;
	}
	int mid(){
		if(st>nd){
			if(st>rd&&rd>nd)	return 2;
			if(rd>st)			return 0;
			else 				return 1;
		}else{
			if(st<rd&&rd>nd)	return 2;
			if(rd<st)			return 0;
			else 				return 1;
		}
	}
	int sid(){
		if(st<=nd&&st<=rd)	return 0;
		if(st>=nd&&nd<=rd)	return 1;
		if(rd<=nd&&st>=rd)	return 2;
	}
	bool operator<(man other){
		return max(st,max(nd,rd))>max(other.st,max(other.nd,other.rd));
	}
};
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		man love[100001];
		bool zero2=true,zero3=true;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>love[i].st>>love[i].nd>>love[i].rd;
			zero2=zero2&&!love[i].nd;
			zero3=zero3&&!love[i].rd;

		}
		if(zero2&&zero3){    //A
			sort(love,love+n);
			int ans=0;
			for(int i=0;i<n/2;i++){
				ans+=love[i].st;
			}
			cout<<ans<<endl;
		}
		else if(zero3){
			sort(love,love+n);
			int ans=0;
			int club[3]={};
			for(int i=0;i<n;i++){
				if(club[love[i].bid()]<n/2){
					club[love[i].bid()]++;
					ans+=love[i].get(love[i].bid());
				}else if(club[love[i].mid()]<n/2){
					club[love[i].mid()]++;
					ans+=love[i].get(love[i].mid());
				}else{
					club[love[i].sid()]++;
					ans+=love[i].get(love[i].sid());
				}
			}
			cout<<ans<<endl;
		}
	}
}
/*
 * 啊啊今年S组好难第一题就不会
 * 先把头文件和freopen写出来吧
 * 『因果』『强运』一起上吧！！！！！！！！
 * 江若雪，云瑶，算我求你俩了！！！！！！！
 * 感觉AB都能打出来
 * 不管了先拿下A再说
 * B的话按A排序，然后一个一个选去A还是去B？
 * 6 7
 * 1 114514
 * 怎么办？
 * 或者按和排序？
 * 5 6
 * 1 9
 * 怎么办？
 * 要不按最大值排序？这个好像可以，感觉三个放一起都可以，先试试吧
 * 等会我先把他改成结构体
 * 爆炸爆炸
 * 4 0
 * 10 9
 * 他丫不行
 * 啊啊啊『因果』助我！！！！！
 * 先交上去再说，反正还有A
 * */
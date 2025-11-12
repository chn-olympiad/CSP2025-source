#include<bits/stdc++.h>
using namespace std;
struct ren{
	int a1,a2,a3;
	int amax;
};
struct ami{
	int ni;
	int ai;
};
ami a1[50000],a2[50000],a3[50000]; 
int t,n;
long long ans;
int ai1,ai2,ai3;
vector<ren> ni;
int sot1(){
	int minn=999999;
	int id;
	for(int i=0;i<ai1;i++){
		if(minn>a1[i].ai){
			minn=a1[i].ai;
			id=i;
		}
	}
	return  id;
}
int sot2(){
	int minn=999999;
	int id;
	for(int i=0;i<ai2;i++){
		if(minn>a2[i].ai){
			minn=a2[i].ai;
			id=i;
		}
	}
	return  id;
}
int sot3(){
	int minn=999999;
	int id;
	for(int i=0;i<ai3;i++){
		if(minn>a3[i].ai){
			minn=a3[i].ai;
			id=i;
		}
	}
	return  id;
}
void maxn(int i1,int i2,int i3,int i){
	int id;
	if(i1>i2&&i1>i3){
				if(ai1<n/2){//判断是否满人 
					a1[ai1].ai=i1;//加入数组 
					a1[ai1].ni=i;//
					ans+=i1;//更新答案 
					ai1++;//更新人数 
				}else{
					id=sot1();//找最小位置 
					if(i1>a1[id].ai){//是否替换 
						int in=a1[id].ni;
						ans-=a1[id].ai;//更新答案 
						ans+=i1;//
						a1[id].ai=i1;//更新人选 
						a1[id].ni=i;//
						id=in;	
						maxn(-1,ni[a1[id].ni].a2,ni[a1[id].ni].a3,a1[id].ni);//被替换的重新选 
					}
				}
			}else if(i2>i1&&i2>i3){
				if(ai2<n/2){
					a2[ai2].ai=i2;
					a2[ai2].ni=i;
					ans+=i2;
					ai2++;
				}else{
					id=sot2();
					if(i2>a2[id].ai){
						int in=a2[id].ni;
						ans-=a2[id].ai;
						ans+=i2;	
						a2[id].ai=i2;
						a2[id].ni=i;
						id=in;
						maxn(ni[a2[id].ni].a1,-1,ni[a2[id].ni].a3,a3[id].ni);
					}
				}
			}else {
				if(ai3<n/2){
					a3[ai3].ai=i3;
					a3[ai3].ni=i;
					ans+=i3;
					ai3++;
				}else{
					id=sot3();
					if(i3>a3[id].ai){
						int in=a3[id].ni;
						ans-=a3[id].ai;
						ans+=i3;
						a3[id].ai=i3;
						a3[id].ni=i;
						id=in;
						maxn(ni[a3[id].ni].a1,ni[a3[id].ni].a2,-1,a3[id].ni);	
					}
				}
			}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int how=0;how<t;how++){
		cin>>n;
		ans=0;ai1=0,ai2=0,ai3=0;
		ni.resize(0);
		for(int i=0;i<n;i++){
			int i1,i2,i3;ren o;
			ni.push_back(o);
			cin>>i1>>i2>>i3;
			ni[i].a1=i1;ni[i].a2=i2;ni[i].a3=i3;
			maxn(i1,i2,i3,i);
		}
		cout<<ans<<endl;
	}
	return 0;
}

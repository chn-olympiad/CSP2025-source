#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
struct mate{
	int x,y,z,cha;
}stu[100005];
int n;
int min(int a,int b){
	if(a<b)return a;
	else return b;
}
bool cmp(mate a,mate b){
	return a.cha>b.cha;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int k=0;k<t;k++){
		cin>>n;
		vector<mate> a,b,c;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>stu[i].x>>stu[i].y>>stu[i].z;//´Ó0¿ªÊ¼ 
			if((stu[i].x>=stu[i].y)&&(stu[i].x>=stu[i].z)){
				stu[i].cha=min(stu[i].x-stu[i].y,stu[i].x-stu[i].z);
				a.push_back(stu[i]);
				ans+=stu[i].x;
			}
			else if((stu[i].y>=stu[i].x)&&(stu[i].y>=stu[i].z)){
				stu[i].cha=min(stu[i].y-stu[i].x,stu[i].y-stu[i].z);
				b.push_back(stu[i]);
				ans+=stu[i].y;
			}
			else {
				stu[i].cha=min(stu[i].z-stu[i].x,stu[i].z-stu[i].y);
				c.push_back(stu[i]);
				ans+=stu[i].z;
			}
		}
		sort(a.begin(),a.end(),cmp);
		sort(b.begin(),b.end(),cmp);
		sort(c.begin(),c.end(),cmp);
		if(a.size()*2>n){
			for(int i=a.size()-1;i*2>=n;i--)
				ans-=a[i].cha;
		}
		else if(b.size()*2>n){
			for(int i=b.size()-1;i*2>=n;i--)
				ans-=b[i].cha;
		}
		else {
			for(int i=c.size()-1;i*2>=n;i--)
				ans-=c[i].cha;
		}
		cout<<ans<<endl;
	}
	return 0;
}

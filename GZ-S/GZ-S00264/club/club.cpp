//GZ-S00264 YangChengjin HLXX
#include<bits/stdc++.h>
using namespace std;
struct stu{
	int a1,a2,a3,wa1,wa2,wa3,wn1,wn2,wn3;
	// 原始，意向排名，好感排名 
}a[100005];
bool cmp(stu x,stu y){
	if(x.wa1==y.wa1){
		if((x.wn1-x.wn2)!=(y.wn1-y.wn2))return (x.wn1-x.wn2)>(y.wn1-y.wn2);
		if((x.wn2-x.wn3)!=(y.wn2-y.wn3))return (x.wn2-x.wn3)>(y.wn2-y.wn3);
	}
	if(x.wn1!=y.wn1)return x.wn1>y.wn1;
	if(x.wn2!=y.wn2)return x.wn2>y.wn2;
	return x.wn3>=y.wn3;
}	   
int t,n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int cl[4]={0,0,0,0},sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if( a[i].a1>=a[i].a2 && a[i].a1>=a[i].a3 ){//志愿 
				a[i].wa1=1,a[i].wn1=a[i].a1;
				if(a[i].a2>=a[i].a3) a[i].wa2=2,a[i].wa3=3   ,a[i].wn2=a[i].a2,a[i].wn3=a[i].a3;
				else a[i].wa2=3,a[i].wa3=2,   a[i].wn2=a[i].a3,a[i].wn3=a[i].a2;
			}
			else if( a[i].a2>=a[i].a1 && a[i].a2>=a[i].a3 ){
				a[i].wa1=2,a[i].wn1=a[i].a2;
				if(a[i].a1>=a[i].a3) a[i].wa2=1,a[i].wa3=3, a[i].wn2=a[i].a1,a[i].wn3=a[i].a3;
				else a[i].wa2=3,a[i].wa3=1,   a[i].wn2=a[i].a3,a[i].wn3=a[i].a1;
			}
			else{
				a[i].wa1=3,a[i].wn1=a[i].a3;
				if(a[i].a1>=a[i].a2) a[i].wa2=1,a[i].wa3=2, a[i].wn2=a[i].a1,a[i].wn3=a[i].a2;
				else a[i].wa2=2,a[i].wa3=1,   a[i].wn2=a[i].a2,a[i].wn3=a[i].a1;
			}
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(cl[ a[i].wa1 ]<n/2)cl[ a[i].wa1 ]++,sum+=a[i].wn1;
			else if(cl[ a[i].wa2 ]<n/2)cl[ a[i].wa2 ]++,sum+=a[i].wn2;
			else cl[ a[i].wa3 ]++,sum+=a[i].wn3;
		}
		cout<<sum<<"\n";
	}
	return 0;//by-ycj
}
/*

1、 最大值在同一个上
                    
2、 切换小者的损失大于切换大者的损失 

1 2 1
2 2 1
2 1 1
1 1 1

*/

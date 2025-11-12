//GZ-S00371  罗裔然  贵阳三中 
#include<bits/stdc++.h>
using namespace std;
long long  t,n,a[100005][3],c[5],as1,as2,as3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++)cin>>a[i][j];
		}
		for(int i=0;i<n;i++){
			as1=a[i][0];
			as2=a[i][1];
			as3=a[i][2];
			if(as1>as2&&as1>as3)c[1]++;
			else if(as2>as1&&as2>as3)c[2]++;
			else if(as3>as1&&as3>as2)c[3]++;
	}
		for(int i=1;i<=3;i++)cout<<c[i]<<endl;
	}
	return 0;
	//555 请求支援 我太fw了
	//兄弟们，不会做！！！
	//老师，你能给我10分吗？？
	//老师，我不想爆0！！！
	//一分也行！！！
	 
}

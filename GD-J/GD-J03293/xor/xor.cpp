#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Max 10005
ll a[Max];
struct mumber{
	int l,r;
}ok[Max];
struct pai{
	int len;
	int num;
};
vector<pai> data,data2;
int xior(int a,int b){
	vector<int> a2,b2,a3,b3;
	int n,num=0;
	vector<int> ans;
// 短除法 
	while(a!=0){
		a2.push_back(a%2);
		a=a/2;
	}
	while(b!=0){
		b2.push_back(b%2);
		b=b/2;
	}
//  补零 
    while(a2.size()<b2.size()){
    	a2.push_back(0);
	}
	while(a2.size()>b2.size()){
    	b2.push_back(0);
	}
//二进制反数 
	for(int i=a2.size()-1;i>=0;i--) a3.push_back(a2[i]);
	for(int i=b2.size()-1;i>=0;i--) b3.push_back(b2[i]);
// 验证
//cout<<endl;
// 	for(int i=0;i<a3.size();i++) cout<<a3[i];
// 	cout<<endl;
// 	for(int i=0;i<b3.size();i++) cout<<b3[i];
// 	cout<<endl;
//抑或
    for(int i=0;i<a3.size();i++){
    	if(a3[i]==b3[i])
    	ans.push_back(0);
    	else
    	ans.push_back(1);
	}  
//二进制回归
	n=1;
//	cout<<endl<<"xor:";
    for(int i=ans.size()-1;i>=0;i--){
//    	cout<<ans[i];
    	num+=n*ans[i];
    	n*=2;
	} 
//	cout<<" "<<n<<"num:"<<num;
//	cout<<endl;
//	cout<<endl<<num<<endl;
	return num;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n=0,k=0,old=0,size=0,num=0;
	pai now;
	now.num=0,now.len=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
 	for(int i=n;i>0;i--){
 		size=data.size();
 		
 		for(int j=0;j<size;j++){
 			now.num=xior(a[i],data[j].num);
 			cout<<a[i]<<" "<<data[j].num<<" "<<i<<" "<<i+data[j].len<<" "<<now.num<<" "<<xior(a[i],data[j].num)<<endl;
 			now.len=data[j].len;
 			if(now.num==k){
 				ok[num].l=i,ok[num].r=i+now.len,num++; 
			 } 
 			data2.push_back(now);
		 }
		 now.num=a[i],now.len=1;
		 data2.push_back(now);
 		data.empty();
 		data=data2;
 		data.empty();
 	}
// 	for(int i=0;i<num;i++){
// 		cout<<ok[i].l<<" "<<ok[i].r<<endl;
//	 }
cout<<1;
	return 0;
} 
/*
4 3
2 1 0 3
*/

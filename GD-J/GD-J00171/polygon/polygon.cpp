#include<bits/stdc++.h>
//code by twly
//keda is DarSharBee! 
using namespace std;
int a[1000001]={0};
int n;
int cnt=0;
void xuanshu(int z,int k,int sum,int as,int maxn){
	for(int i=as;i<=n;i++){
		if(k==1){
			maxn=0;
		}
		if(i>as){
			sum-=a[i-1];
			sum+=a[i];
			if(a[i]>maxn){
				maxn=a[i];
			}
		}
		else{
			sum+=a[i];
			if(a[i]>maxn){
				maxn=a[i];
			}
		}
		if(k==z||z>n){
			if(sum>maxn*2){
				cnt++;
				//cout<<"sum:"<<sum<<endl;
				//cout<<"zuidazhi:"<<a[j-1]*2<<endl;
				//cout<<"cnt:"<<cnt<<endl;
				//for(int k=1;k<=z;k++){
				//	cout<<a[j-k]<<" ";
				//}
				//cout<<endl;
				//cout<<a[i]<<" "<<endl;
				//cout<<"maxn:"<<maxn<<endl;
				//cout<<"end"<<endl;
				//cout<<"sum:"<<sum<<endl;
			}
		}
		k++;
		//cout<<"i:"<<i<<endl;
		//cout<<"as:"<<as<<endl;
		//cout<<a[i]<<" ";
		if(k<=z){
			xuanshu(z,k,sum,i+1,maxn);
		}
		k--;
	}
	//cout<<"end"<<endl;
}
/*int dfs(int z){
	int cnt=0;
	for(int i=z;i<=n;i++){
		int sum=0,s=1;
		int j;
		for(j=i-z+1;s<=z;j++){
			//cout<<"s:"<<s<<endl;
			sum+=a[j];
			//cout<<"xvanshu"<<j<<":"<<a[j]<<endl;
			s++;
		}
		//cout<<"_____"<<sum<<endl;
		//cout<<"a[j]:"<<a[j-1]*2<<endl;
		if(sum>a[j-1]*2){
			cnt++;
			//cout<<"sum:"<<sum<<endl;
			//cout<<"zuidazhi:"<<a[j-1]*2<<endl;
			//cout<<"cnt:"<<cnt<<endl;
			//for(int k=1;k<=z;k++){
			//	cout<<a[j-k]<<" ";
			//}
			//cout<<endl;
		}
	}
	return cnt;
}
*/
int main(){
	freopen("polygon.in","r","stdin");
	freopen("polygon.out","w","stdout");
	cin>>n;
	int k=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n); 
	for(int i=3;i<=n;i++){
		xuanshu(i,1,0,1,0);
	}
	cout<<endl;
	cout<<cnt;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[100005];
int x(int b,int c){
	if(b==0&&c==0)return 1;
	bool s1[22]={0},s2[22]={0};
	int top_1=0,top_2=0;
	int num=0;
	while(b>0){
		top_1++;
		if(b%2==1)s1[top_1]=1;
		b/=2;
		//cout<<s1[top_1];
	}
	//cout<<endl;
	while(c>0){
		top_2++;
		if(c%2==1)s2[top_2]=1;
		c/=2;
		//cout<<s2[top_2];
	}
	//cout<<endl;
	for(int i=max(top_1,top_2);i>=1;i--){
		if(s1[i]!=s2[i])num++;
		//cout<<s1[i]<<" "<<s2[i]<<" "<<num<<" ";
		if(i!=1)num*=2;
	}
	//cout<<endl;
	return num;
}
int xa(int b,int c){
	if(b==c)return a[b];
	int num=a[b];
	for(int i=b+1;i<=c;i++){
		//cout<<num<<" "<<a[i]<<":"<<endl;
		num=x(num,a[i]);
		//cout<<"_______"<<num<<endl;
	}
	return num;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(xa(i,j)==m){
				ans++;
				/*for(int w=i;w<=j;w++){
				cout<<a[w]<<" ";
				}*/
				//cout<<endl;
				i=j;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
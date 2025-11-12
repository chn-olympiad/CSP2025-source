#include<bits/stdc++.h>
using namespace std;
int f1(int x){
	int a=0,num=1;
	while(x!=0){
		a+=x%2*num;
		num*=10;
		x/=2;
	}
	return a;
}
int f2(int a){
	int sum=0,i=0;
	while(a!=0){
		sum+=a%10*pow(2,i);
		a/=10;
		i++;
	}
	return sum;
}
int f(int a,int b){
	int x=f1(a),y=f1(b);
	string s;
	while(x!=0||y!=0){
		s+=!((x%10)&(y%10))+'0';
		x/=10;
		y/=10;
	}
	int c=0;
	for(int i=s.size()-1;i>=0;i--){
		c*=10;
		c+=s[i]-'0';
	}
	return f2(c);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum=0;
	cin>>n>>k;
	int a[n+1];
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=1;i<n;i++){
		int num=a[i-1];
		for(int j=i;j<n;j++){
			if(num==k){
				sum++;
				i=j;
				break;
			}
			else{
				num=f(a[j],num);
				if(num==k){
				sum++;
				i=j;
				break;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}

#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
int a[10005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
int n,cnt=0,sum1=0,maxm=-1;
cin>>n;
for(int i=1;i<=n;i++){
	int x;
	cin>>x;
	a[i]=x;
	sum1+=x;
	maxm=max(x,maxm);
}
sort(a+1,a+n+1);
if(n==3){
	if(sum1>(maxm*2)){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
for(int i=3;i<=n;i++){
    bool v[10005];
	int sz=i;
	stack <int>s;
	int maxn=-1,sum=0;
	int j=1;
	while(j<=n){
		if(s.size()<sz){
			if(v[j]!=1){
				s.push(a[j]);
				//cout<<a[j]<<" ";
				v[j]=1;
				sum+=a[j];
				maxn=a[j];
				j++;
				//cout<<j<<" ";		
			}
			else{
				j++;
			}		
		}						
 		else if(s.size()==sz){
				s.pop();
				j++;
				if(v[j]==1){
					j++;
				}
				else{
					s.push(a[j]);
				}
			}
		if(sum>(maxn*2)&&s.size()==sz)cnt++;
		}
	}
	cout<<cnt;	
	return 0;
}

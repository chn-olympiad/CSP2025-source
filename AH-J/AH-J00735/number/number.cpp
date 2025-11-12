#include<bits/stdc++.h>
using namespace std;
string a,sum;
long long t=0;
int b[1000010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    long long n=a.size();
    for(long long i=0;i<n;i++){
		if(a[i]>='0'&&a[i]<='9'){
			t++;
			sum[t]=a[i];
		}
	}
	for(long long i=1;i<=t;i++){
		if(sum[i]=='0')b[i]=0;
		else if(sum[i]=='1')b[i]=1;
		else if(sum[i]=='2')b[i]=2;
		else if(sum[i]=='3')b[i]=3;
		else if(sum[i]=='4')b[i]=4;
		else if(sum[i]=='5')b[i]=5;
		else if(sum[i]=='6')b[i]=6;
		else if(sum[i]=='7')b[i]=7;
		else if(sum[i]=='8')b[i]=8;
		else if(sum[i]=='9')b[i]=9;
	}
	sort(b+1,b+t+1,cmp);
	for(long long i=1;i<=t;i++)cout<<b[i];
    return 0;
}

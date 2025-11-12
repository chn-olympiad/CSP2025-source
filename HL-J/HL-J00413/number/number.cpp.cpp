#include<bits/stdc++.h>
using namespace std;
bool cmp(long long  a,long long  b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string z;
	cin>>z;
	long long arr[100005]={},num=0;
	long long l=z.length();
	for(long long i=0;i<l;i++){
		if(z[i]=='0') arr[num++]=0;
		if(z[i]=='1') arr[num++]=1;
		if(z[i]=='2') arr[num++]=2;
		if(z[i]=='3') arr[num++]=3;
		if(z[i]=='4') arr[num++]=4;
		if(z[i]=='5') arr[num++]=5;
		if(z[i]=='6') arr[num++]=6;
		if(z[i]=='7') arr[num++]=7;
		if(z[i]=='8') arr[num++]=8;
		if(z[i]=='9') arr[num++]=9;
	}
	long long sum=0;
	sort(arr,arr+num,cmp);
	for(long long i=0;i<num;i++){
		sum=sum*10+arr[i];
	}
	printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

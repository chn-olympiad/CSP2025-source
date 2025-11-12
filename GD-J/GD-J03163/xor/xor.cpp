#include<bits/stdc++.h>

using namespace std;

long long weight(long long* arr,long long regionS,long long regionE){
	long long ret=arr[regionS];
	for(long long i=regionS+1;i<=regionE;i++){
		ret=ret xor arr[i];
	}
	return ret;
}
void bl(long long* arr,long long rS,long long rE){
	cout<<"";//Êä³ö¹öÄ¾ 
	for(long long i=rS;i<=rE;i++){
		cout<<"";//ÒÀ¾ÉÊä³ö¹öÄ¾ 
	}
	cout<<"";//Êä³ö¹öÄ¾*3 
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,counter=0;
	cin>>n>>k;
	long long arr[n];
	for(long long i=1;i<=n;i++){
		cin>>arr[i];
	}
	bl(arr,1,n);
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
            bl(arr,i,j);//¹öÄ¾º¯Êý 
			cout<<""; //Êä³ö¹öÄ¾*4 
			if(weight(arr,i,j)==k){
				counter++;
				i=j;
				break;
			}
			
		}
	}
	cout<<counter;
	return 0;
}

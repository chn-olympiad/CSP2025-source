#include<bits/stdc++.h>
using namespace std;

int n,n1;
int ss[5005];
long long num;


int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ss[i];
		if(ss[i]==1){
			n1++;
		}
	}
	
//	cout<<n1<<"¡¡"; 
	
	sort(ss+1,ss+n+1);
	
	if(n==3){
		if(ss[1]+ss[2]>ss[3] &&
			ss[3]+ss[2]>ss[1] &&
			ss[1]+ss[3]>ss[2]
		){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	
	if(n==n1){
		long long numm=1;
		int ok=2;
		for(int i=n-2;i;i--){
//			cout<<num<<" "<<numm<<" "<<ok<<endl;
			num=(num+numm*i)%1000000000;
			numm+=ok;
			ok++;
//			cout<<endl;
		}
		cout<<num%998244353;
		return 0;
	}
	
	return 0;
}





//#include<bits/stdc++.h>
//using namespace std;
//
//int n;
//int ss[5005];
//int sa[5005];
//int sy[5005];
//int sz[5005];
//int maxs;
//long long num;
//
//
//
//int main(){
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		int okk;
//		cin>>okk;
//		sy[i]=okk;
//		ss[okk]++;
//		maxs=max(maxs,okk);
//	}
//	
//	sort(sy+1,sy+n+1);
//	
//	int t=1;
//	for(int i=1;i<=maxs;i++){
//		if(ss[i]!=0){
//			sa[t]=i;
//			t++;
//		}
//	}
//	
////	for(int i=1;i<=100;i++){
////		cout<<s[i]<<" ";
////	}
//	cout<<maxs;
//	for(int i=1;i<=n;i++){
//		sz[1]=i;
//		sz[2]=i+1;
//		int dz=sy[i]+sy[i+1];
//		for(int j=2;j<=n;j++){
//			for(k=1;k;k++){
//				if(dz>sz[j+k]){
//					if(sy[sz[j]]==sy[sz[j]+1]){
//						
//					}else{
//						
//					}
//				}else{
//					break;
//				}
//			}
//		}
//	}
//	return 0;
//}

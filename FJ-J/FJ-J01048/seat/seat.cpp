#include<bits/stdc++.h>
using namespace std;
//bool cmp(int a,int b){
//	return a>b;
//}
long long n,m,c,arr[11][11],s[121],mx=0,st;
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.in","r",stdout);
	scanf("%lld %lld %lld",&n,&m,&c);
	st=c;
	s[0]=101;
	s[1]=c;
	for(int i =2;i <= n*m;++i){
		scanf("%lld",&c);
		s[i]=c;		
	}
	
	
//	sort(s,s+1,cmp);
	for(int i =1;i <=n*m;++i){
		for(int j =1;j <=n*m;++j){
			if(s[j]>s[j-1]){
				swap(s[j],s[j-1]);
			}
		}
		
	}	
	

	
	
	
	int x=1;
	
	for(int i = 1;i <= m;++i){
		if(x%2!=0){
			cout<<9;
			for(int j =1;j <= n;++j){
				arr[j][i]=s[];
//				for(int k =n*(i-1)+1;k <= n*i;++k){
//					
//					arr[j][i]=s[k];
//					
//				}
			}
			x+=1;
			
		}
		else{
			cout<<8;
			for(int j =n;j >= 1;--j){
				for(int k = n*(i-1)+1 ;k >= n*i;++k){
					arr[j][i]=s[k];
				}
			}
			x++;
		}
		
	}
	for(int i =1;i <=n;++i){
		for(int j =1;j <=m;++j){
			cout<<arr[i][j]<<" ";
//			if(arr[i][j]=st){
//				cout<<i<<j<<" ";
//				break;
//			}
		}
		cout<<endl;
	}
	return 0;
}

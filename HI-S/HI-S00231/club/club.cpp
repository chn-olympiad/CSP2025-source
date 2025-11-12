#include<bits/stdc++.h>
using namespace std;
long long s[1000010],a[1000010],b[100010],c[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long n,m,f=1;
	cin>>m;
	for(long long j=0;j<m;j++){
		cin>>n;
		long long sum1=0,sum2=0,sum3=0;
		for(long long i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]){
				s[i]=a[i];
				sum1++;
			}else if(b[i]>=a[i]&&b[i]>=c[i]){
				s[i]=b[i];
				sum2++;
			}else{
				s[i]=c[i];
				sum3++;
			}
		}
		long long mi=1000000,mn=0;
		while((max(sum1,sum2)-min(sum1,sum2))>(n/2)||(max(sum1,sum3)-min(sum1,sum3))>(n/2)||(max(sum2,sum3)-min(sum2,sum3))>(n/2)){
			//1-2
			if((sum1-sum2)>n/2){
				while((sum1-sum2)>n/2){
					for(long long i=0;i<n;i++){
						if(s[i]==a[i]&&(a[i]-b[i])<mi){
							mi=a[i]-b[i];
							mn=i;
						}
					}
					s[mn]=b[mn];
					sum1--;
					sum2++;
					
					
				}
			}
	
	      if((max(sum1,sum2)-min(sum1,sum2))<=(n/2)&&(max(sum1,sum3)-min(sum1,sum3))<=(n/2)&&(max(sum2,sum3)-min(sum2,sum3))<=(n/2)){
				long long num=0;
				for(long long i=0;i<n;i++){
					num+=s[i];
				}
				cout<<num<<endl;
				f=0;
				break;
			}
			//1-3
			mi=1000000,mn=0;
			if((sum1-sum3)>n/2){
				while((sum1-sum3)>n/2){
					for(long long i=0;i<n;i++){
						if(s[i]==a[i]&&(a[i]-c[i])<mi){
							mi=a[i]-c[i];
							mn=i;
						}
					}
					s[mn]=c[mn];
					sum1--;
					sum3++;
				}
			}
			
			
			
			if((max(sum1,sum2)-min(sum1,sum2))<=(n/2)&&(max(sum1,sum3)-min(sum1,sum3))<=(n/2)&&(max(sum2,sum3)-min(sum2,sum3))<=(n/2)){
				long long num=0;
				for(long long i=0;i<n;i++){
					num+=s[i];
				}
				cout<<num<<endl;
				f=0;
				break;
			}
			//2-1
			mi=1000000,mn=0;
			if((sum2-sum1)>(n/2)){
				while((sum2-sum1)>(n/2)){
					for(long long i=0;i<n;i++){
						if(s[i]==b[i]&&(b[i]-a[i])<mi){
							mi=b[i]-a[i];
							mn=i;
						}
						
					}
					s[mn]=a[mn];
					sum2--;
					sum1++;
				}
			}
			
			if((max(sum1,sum2)-min(sum1,sum2))<=(n/2)&&(max(sum1,sum3)-min(sum1,sum3))<=(n/2)&&(max(sum2,sum3)-min(sum2,sum3))<=(n/2)){
				long long num=0;
				for(long long i=0;i<n;i++){
					num+=s[i];
				}
				cout<<num<<endl;
				f=0;
				break;
			}	
			//2-3
			mi=1000000,mn=0;
			if((sum2-sum3)>n/2){
				while((sum2-sum3)>n/2){
					for(long long i=0;i<n;i++){
						if(s[i]==b[i]&&(b[i]-c[i])<mi){
							mi=b[i]-c[i];
							mn=i;
						}
					}
					s[mn]=c[mn];
					sum2--;
					sum3++;
				}
			}
			
			if((max(sum1,sum2)-min(sum1,sum2))<=(n/2)&&max(sum1,sum3)-min(sum1,sum3)<=(n/2)&&(max(sum2,sum3)-min(sum2,sum3))<=(n/2)){
				long long num=0;
				for(long long i=0;i<n;i++){
					num+=s[i];
					
				}
				cout<<num<<endl;
				f=0;
				break;
			}
			
			
			
			//3-1
			mi=1000000,mn=0;
			if((sum3-sum1)>(n/2)){
				while((sum3-sum1)>(n/2)){
					for(long long i=0;i<n;i++){
						if(s[i]==c[i]&&(c[i]-a[i])<mi){
							mi=c[i]-a[i];
							mn=i;
						}
					}
					s[mn]=a[mn];
					sum3--;
					sum1++;
				}
			}
			
			
			
			if((max(sum1,sum2)-min(sum1,sum2))<=(n/2)&&max(sum1,sum3)-min(sum1,sum3)<=(n/2)&&(max(sum2,sum3)-min(sum2,sum3))<=(n/2)){
				long long num=0;
				for(long long i=0;i<n;i++){
					num+=s[i];
					
				}
				cout<<num<<endl;
				f=0;
				break;
			}
			
			//3-2
			mi=1000000,mn=0;
			if((sum3-sum2)>(n/2)){
				while((sum3-sum2)>(n/2)){
					for(long long i=0;i<n;i++){
						if(s[i]==c[i]&&(c[i]-b[i])<mi){
							mi=c[i]-b[i];
							mn=i;
						}
					}
					s[mn]=b[mn];
					sum3--;
					sum2++;
				}
			}
			if((max(sum1,sum2)-min(sum1,sum2))<=(n/2)&&(max(sum1,sum3)-min(sum1,sum3))<=(n/2)&&(max(sum2,sum3)-min(sum2,sum3))<=(n/2)){
				long long num=0;
				for(long long i=0;i<n;i++){
					num+=s[i];
					
				}
				cout<<num<<endl;
				f=0;
				break;
			}
		}
		if(f==1){
			long long num=0;
			for(long long i=0;i<n;i++){
				num+=s[i];		
			}
			cout<<num<<endl;
			f=1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

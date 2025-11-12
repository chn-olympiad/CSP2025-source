#include<bits/stdc++.h>
using namespace std;
long long t,n,a[10005][10005],f[10005];
long long ma1=-1,ma2=-1,ma3=-1,maa1,maa2,maa3,mma1,mma2;
long long r1,r2,r3;
long long ans;
int main(){
	freopen("club","r",stdin);
	freopen("club","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		ma1=-1;
		ma2=-1;
		ma3=-1;
		cin>>n;
		for(long long i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
	    }
      	for(long long i=1;i<=n;i++){
		    if(ma1<a[i][1]&&f[i]==0){
				maa1=i;
				ma1=max(ma1,a[i][1]);
			}
			if(ma2<a[i][2]&&f[i]==0){
				maa2=i;
				ma2=max(ma2,a[i][2]);
			}
			if(ma3<a[i][3]&&f[i]==0){
				maa3=i;
				ma3=max(ma3,a[i][3]);
			}
			if(maa1>=maa2&&maa2>=maa3){//123
				if(maa1!=maa2&&maa1!=maa3&&r1+1<=n/2&&f[maa1]==0){
				ans+=ma1;
				f[maa1]=1;
				r1++;
				cout<<1<<" "<<maa1<<" "<<ma1<<"       mmmm";
			}
			if(maa2!=maa1&&maa2!=maa3&&r2+1<=n/2&&f[maa2]==0){
				ans+=ma2;
				f[maa2]=1;
				r2++;
				cout<<2<<" "<<maa2<<" "<<ma2<<"       mmmm";
				
			}
			if(maa3!=maa1&&maa3!=maa2&&r3+1<=n/2&&f[maa3]==0){
				ans+=ma3;
				f[maa3]=1;
				r3++;
				cout<<3<<" "<<maa3<<" "<<ma3<<"       mmmm";
			}
			}else if(maa1>=maa3&&maa3>=maa2){//132
				if(maa1!=maa2&&maa1!=maa3&&r1+1<=n/2&&f[maa1]==0){
				ans+=ma1;
				f[maa1]=1;
				r1++;
				cout<<1<<" "<<maa1<<" "<<ma1<<"       mmmm";
		    	}
		    	if(maa3!=maa1&&maa3!=maa2&&r3+1<=n/2&&f[maa3]==0){
				ans+=ma3;
				f[maa3]=1;
				r3++;
				cout<<3<<" "<<maa3<<" "<<ma3<<"       mmmm";
		    	}
				if(maa2!=maa1&&maa2!=maa3&&r2+1<=n/2&&f[maa2]==0){
				ans+=ma2;
				f[maa2]=1;
				r2++;
				cout<<2<<" "<<maa2<<" "<<ma2<<"       mmmm";
		    	}
			}else if(maa2>=maa1&&maa1>=maa3){//213
			    if(maa2!=maa1&&maa2!=maa3&&r2+1<=n/2&&f[maa2]==0){
				ans+=ma2;
				f[maa2]=1;
				r2++;
				cout<<2<<" "<<maa2<<" "<<ma2<<"       mmmm";
		    	}
				if(maa1!=maa2&&maa1!=maa3&&r1+1<=n/2&&f[maa1]==0){
				ans+=ma1;
				f[maa1]=1;
				r1++;
				cout<<1<<" "<<maa1<<" "<<ma1<<"       mmmm";
		    	}
		    	if(maa3!=maa1&&maa3!=maa2&&r3+1<=n/2&&f[maa3]==0){
				ans+=ma3;
				f[maa3]=1;
				r3++;
				cout<<3<<" "<<maa3<<" "<<ma3<<"       mmmm";
		    	}
			}else if(maa1>=maa3&&maa3>=maa2){//231
		    	if(maa2!=maa1&&maa2!=maa3&&r2+1<=n/2&&f[maa2]==0){
				ans+=ma2;
				f[maa2]=1;
				r2++;
				cout<<2<<" "<<maa2<<" "<<ma2<<"       mmmm";
		    	}
		    	if(maa3!=maa1&&maa3!=maa2&&r3+1<=n/2&&f[maa3]==0){
				ans+=ma3;
				f[maa3]=1;
				r3++;
				cout<<3<<" "<<maa3<<" "<<ma3<<"       mmmm";
		    	}
				if(maa1!=maa2&&maa1!=maa3&&r1+1<=n/2&&f[maa1]==0){
				ans+=ma1;
				f[maa1]=1;
				r1++;
				cout<<1<<" "<<maa1<<" "<<ma1<<"       mmmm";
		    	}
			}else if(maa1>=maa3&&maa3>=maa2){//312
		    	if(maa3!=maa1&&maa3!=maa2&&r3+1<=n/2&&f[maa3]==0){
				ans+=ma3;
				f[maa3]=1;
				r3++;
				cout<<3<<" "<<maa3<<" "<<ma3<<"       mmmm";
		        }
		        if(maa1!=maa2&&maa1!=maa3&&r1+1<=n/2&&f[maa1]==0){
				ans+=ma1;
				f[maa1]=1;
				r1++;
				cout<<1<<" "<<maa1<<" "<<ma1<<"       mmmm";
		    	}
				if(maa2!=maa1&&maa2!=maa3&&r2+1<=n/2&&f[maa2]==0){
				ans+=ma2;
				f[maa2]=1;
				r2++;
				cout<<2<<" "<<maa2<<" "<<ma2<<"       mmmm";
		    	}
		    	
			}else if(maa1>=maa3&&maa3>=maa2){//321
		    	if(maa3!=maa1&&maa3!=maa2&&r3+1<=n/2&&f[maa3]==0){
				ans+=ma3;
				f[maa3]=1;
				r3++;
				cout<<3<<" "<<maa3<<" "<<ma3<<"       mmmm";
		    	}
				if(maa2!=maa1&&maa2!=maa3&&r2+1<=n/2&&f[maa2]==0){
				ans+=ma2;
				f[maa2]=1;
				r2++; 
				cout<<2<<" "<<maa2<<" "<<ma2<<"       mmmm";
		    	}
		    	if(maa1!=maa2&&maa1!=maa3&&r1+1<=n/2&&f[maa1]==0){
				ans+=ma1;
				f[maa1]=1;
				r1++;
				cout<<1<<" "<<maa1<<" "<<ma1<<"       mmmm";
		    	}
			}
}
			for(long long i=1;i<=n;i++){
				if(f[i]==0){
					mma1=max(a[i][1],max(a[i][2],a[i][3]));
					long long minn=min(a[i][1],min(a[i][2],a[i][3]));
					mma2=a[i][1]+a[i][2]+a[i][3]-mma1-minn;
					cout<<r1+1<<" "<<n/2; 
		        	if(mma1=a[i][1]&&r1+1==n/2){
						ans+=mma1;
						r1++;
						cout<<ans<<"      ";
						cout<<mma1<<"               ";
						cout<<r1+1<<"                          "<<n/2;
					}else if(mma1=a[i][2]&&r2+1<n/2){
						ans+=mma1;
						r2++;
					}else if(mma1=a[i][3]&&r3+1<=n/2){
						ans+=mma1;
						r3++;
					}else if(mma2=a[i][1]&&r1+1<n/2){
						ans+=mma2;
						r1++;
					}else if(mma2=a[i][2]&&r2+1<=n/2){
						ans+=mma2;
						r2++;
					}else{
						ans+=mma2;
						r3++;
					}
				}
			}
    cout<<ans<<'\n';
	}
	return 0;
} 



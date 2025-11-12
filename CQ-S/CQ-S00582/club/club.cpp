#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct mem{
	int i1,i2,i3;
}a[N];
int t,n;
bool cmp( mem x,mem y ){
	if( x.i1!=y.i1 ){
		return x.i1>y.i1;
	}else if( x.i2!=y.i2 ){
		return x.i2>y.i2;
	}else{
		return x.i3>y.i3;
	}
} 
int main(){
	freopen( "club.in","r",stdin );
	freopen( "club.out","w",stdout );
	cin >> t;
	while( t-- ){
		cin >> n;
		for( int i=1;i<=n;i++ ){
			cin >> a[i].i1 >> a[i].i2 >> a[i].i3;
		}
		sort(a+1,a+n+1,cmp);
		int ans=-1;
		for( int i=1;i<=n;i++ ){
			for( int a1=1;a1<=3;a1++ ){
				for( int b1=1;b1<=3;b1++ ){
					for( int c_1=1;c_1<=3;c_1++ ){
						int k=n/2,c1=0,c2=0,c3=0,ans1=0,ans2=0,ans3=0;
						for( int j=1;j<=n;j++ ){
							if(a1==b1&&b1==c_1) continue;
							if(a1==1){
								if(b1==2&&c_1==3){
									if(c1<k){
										if(a[j].i1==max(a[j].i1,max(a[j].i2,a[j].i3))&&c2>=k){
											c1++,ans1+=a[j].i1;
										}else if(a[j].i2==max(a[j].i2,a[j].i3)&&c3>=k){
											c2++,ans2+=a[j].i2;
										}else{
											c3++,ans3+=a[j].i3;
										}
									}else if(c2<k){
										if(a[j].i2==max(a[j].i2,a[j].i3)&&c3>=k){
											c2++,ans2+=a[j].i2;
										}else{
											c3++,ans3+=a[j].i3;
										}
									}else if(c3<k) c3++,ans3+=a[j].i3;
								}else if(b1==3&&c_1==2){
									if(c1<k){
										if(a[j].i1==max(a[j].i1,max(a[j].i2,a[j].i3))&&c2>=k){
											c1++,ans1+=a[j].i1;
										}else if(a[j].i3==max(a[j].i2,a[j].i3)&&c2>=k){
											c3++,ans3+=a[j].i3;
										}else{
											c2++,ans2+=a[j].i2;
										}
									}else if(c3<k){
										if(a[j].i3==max(a[j].i2,a[j].i3)&&c2>=k){
											c3++,ans3+=a[j].i3;
										}else{
											c2++,ans2+=a[j].i2;
										}
									}else if(c2<k) c2++,ans2+=a[j].i2; 
								}
							}else if(a1==2){
								if(b1==1&&c_1==3){
									if(c2<k){
										if(a[j].i2==max(a[j].i1,max(a[j].i2,a[j].i3))&&c1>=k){
											c2++,ans2+=a[j].i2;
										}else if(a[j].i1==max(a[j].i1,a[j].i3)&&c3>=k){
											c1++,ans1+=a[j].i1;
										}else{
											c3++,ans3+=a[j].i3;
										}
									}else if(c1<k){
										if(a[j].i1==max(a[j].i1,a[j].i3)&&c3>=k){
											c1++,ans1+=a[j].i1;
										}else{
											c3++,ans3+=a[j].i3;
										}
									}else if(c3<k) c3++,ans3+=a[j].i3;
								}else if(b1==3&&c_1==1){
									if(c2<k){
										if(a[j].i2==max(a[j].i1,max(a[j].i2,a[j].i3))&&c1>=k){
											c2++,ans2+=a[j].i2;
										}else if(a[j].i3==max(a[j].i1,a[j].i3)&&c1>=k){
											c3++,ans3+=a[j].i3;
										}else{
											c1++,ans1+=a[j].i1;
										}
									}else if(c3<k){
										if(a[j].i3==max(a[j].i1,a[j].i3)&&c1>=k){
											c3++,ans3+=a[j].i3;
										}else{
											c1++,ans1+=a[j].i1;
										}
									}else if(c1<k) c1++,ans1+=a[j].i1;
								}
							}else if(a1==3){
								if(b1==1&&c_1==2){
									if(c3<k){
										if(a[j].i3==max(a[j].i1,max(a[j].i2,a[j].i3))&&c1>=k){
											c3++,ans3+=a[j].i3;
										}else if(a[j].i1==max(a[j].i1,a[j].i2)&&c2>=k){
											c1++,ans1+=a[j].i1;
										}else{
											c2++,ans2+=a[j].i2;
										}
									}else if(c1<k){
										if(a[j].i1==max(a[j].i1,a[j].i2)&&c2>=k){
											c1++,ans1+=a[j].i1;
										}else{
											c2++,ans2+=a[j].i2;
										}
									}else if(c2<k) c2++,ans2+=a[j].i2;
								}else if(b1==2&&c_1==1){
									if(c3<k){
										if(a[j].i3==max(a[j].i1,max(a[j].i2,a[j].i3))&&c2>=k){
											c3++,ans3+=a[j].i3;
										}else if(a[j].i2==max(a[j].i1,a[j].i2)&&c1>=k){
											c2++,ans2+=a[j].i2;
										}else{
											c1++,ans1+=a[j].i1;
										}
									}else if(c2<k){
										if(a[j].i2==max(a[j].i1,a[j].i2)&&c1>=k){
											c2++,ans2+=a[j].i2;
										}else{
											c1++,ans1+=a[j].i1;
										}
									}else if(c1<k) c2++,ans2+=a[j].i2;
								}
							}
						}
						ans=max( ans,ans1+ans2+ans3 );
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

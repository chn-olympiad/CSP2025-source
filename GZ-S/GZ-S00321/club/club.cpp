//GZ-S00321 遵义市南白中学 王文轩 
#include<bits/stdc++.h>
using namespace std;
struct abc{
	int a1;
	int b1;
	int c1;
};
bool cmp(abc a,abc b){
	return a.a1>=b.a1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,ans=0,w=0;
		cin>>n;
		abc s[10000];
		bool A=true,B=true;
		int a[1000][3];
		for(int i=0;i<n;i++){
			cin>>s[i].a1>>s[i].b1>>s[i].c1;
			if(s[i].b1!=0||s[i].c1!=0){
				A=false;
			}
			if(s[i].c1!=0){
				B=false;
			}
			a[i][0]=s[i].a1;
			a[i][1]=s[i].b1;
			a[i][2]=s[i].c1;
		}
		int x[3];
		for(int i=0;i<3;i++){
			x[i]=0;
		}
		if(A){
			sort(s+0,s+n,cmp);
			for(int i=0;i<n/2;i++){
				ans+=s[i].a1;
			}
			cout<<ans<<endl;
			continue;
		}
		if(n==2){
			int d=0;
			for(int i=0;i<3&&x[i]<1;i++,x[i]++){
				for(int j=0;j<3&&x[j]<1;j++,x[j]++){
					d=max(d,a[0][i]+a[1][j]);
					//cout<<x[0]<<' '<<x[1]<<' '<<x[2]<<' '<<i<<' '<<j<<endl;
					for(int p=0;p<3;p++){
						x[p]=0;
					}
				}
			}
			cout<<d<<endl;
			continue;
		}
		if(n==4){
			int d=0;
			for(int i1=0;i1<3&&x[i1]<2;i1++,x[i1]++){
				for(int i2=0;i2<3&&x[i2]<2;i2++,x[i2]++){
					for(int i3=0;i3<3&&x[i3]<2;i3++,x[i3]++){
						for(int i4=0;i4<3&&x[i4]<2;i4++,x[i4]++){
							d=max(d,a[0][i1]+a[1][i2]+a[2][i3]+a[3][i4]);
							//cout<<x[0]<<' '<<x[1]<<' '<<x[2]<<endl;
							for(int p=0;p<3;p++){
								x[p]=0;
							}
						}
					}
				}
			}
			cout<<d<<endl;
			continue;
		}
		if(n==10){
			int d=0;
			for(int i1=0;i1<3&&x[i1]<5;i1++,x[i1]++){
				for(int i2=0;i2<3&&x[i2]<5;i2++,x[i2]++){
					for(int i3=0;i3<3&&x[i3]<5;i3++,x[i3]++){
						for(int i4=0;i4<3&&x[i4]<5;i4++,x[i4]++){
							for(int i5=0;i5<3&&x[i5]<5;i5++,x[i5]++){
								for(int i6=0;i6<3&&x[i6]<5;i6++,x[i6]++){
									for(int i7=0;i7<3&&x[i7]<5;i7++,x[i7]++){
										for(int i8=0;i8<3&&x[i8]<5;i8++,x[i8]++){
											for(int i9=0;i9<3&&x[i9]<5;i9++,x[i9]++){
												for(int i10=0;i10<3&&x[i10]<5;i10++,x[i10]++){
													d=max(d,a[0][i1]+a[1][i2]+a[2][i3]+a[3][i4]+a[4][i5]+a[5][i6]+a[6][i7]+a[7][i8]+a[8][i9]+a[9][i10]);
													for(int p=0;p<3;p++){
														x[p]=0;
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			
			cout<<d<<endl;
			continue;
		}
	} 
	return 0;
} 

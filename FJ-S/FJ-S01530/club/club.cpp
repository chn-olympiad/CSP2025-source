#include<bits/stdc++.h>
using namespace std;
struct A{
	int f;
	int c;
	int d;
}a[100086];
int b[100086][4];
bool cmp1(A s,A g){
	return s.f>g.f;
}
bool cmp2(A s,A g){
	return s.c>g.c;
}
bool cmp3(A s,A g){
	return s.d>g.d;
}
int t,n;
int s1=0,s2=0,s3=0;
void ddd(int n){
	if(n==1)s1++;
	if(n==2)s2++;
	if(n==3)s3++;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].f>>a[i].c>>a[i].d;
		}
		int a1=1,a2=1,a3=1;
		for(int i=1;i<=n;i++){
			if(a[i].f>0)a1=0;
			if(a[i].c>0)a2=0;
			if(a[i].d>0)a3=0;
		}
		if(a3==1&&a2==1){
			sort(a+1,a+n+1,cmp1);
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=a[i].f;
			}
			cout<<ans<<endl;
			continue;
		}
		if(a1==1&&a3==1){
			sort(a+1,a+n+1,cmp2);
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=a[i].c;
			}
			cout<<ans<<endl;
			continue;
		}
		if(a2==1&&a3==1){
			sort(a+1,a+n+1,cmp3);
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=a[i].d;
			}
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			b[i][1]=a[i].f;
			b[i][2]=a[i].c;
			b[i][3]=a[i].d;
		}
		if(a2==1){
			int ans=0;
			for(int i=1;i<=n;i++){
				ans+=max(a[i].f,a[i].c);
			}
			cout<<ans<<endl;
			continue;
		}
		if(n==2){
			int ans=0;
			for(int d1=1;d1<=3;d1++){
				for(int d2=1;d2<=3;d2++){
					if(d1!=d2){
						ans=max(ans,b[1][d1]+b[2][d2]);
					}
				}			
		   }
		   cout<<ans<<endl;
		   continue;
		}
		if(n==4){
			int ans=0;
			s1=0;s2=0;s3=0;
			for(int d1=1;d1<=3;d1++){
				for(int d2=1;d2<=3;d2++){
					for(int d3=1;d3<=3;d3++){
						for(int d4=1;d4<=3;d4++){
							s1=0;s2=0;s3=0;
							ddd(d1);ddd(d2);ddd(d3);ddd(d4);
							if(s1>n/2||s2>n/2||s3>n/2){
								continue;
							}
							ans=max(ans,(b[1][d1]+b[2][d2]+b[3][d3]+b[4][d4]));
						}
					}
				}
			}
			cout<<ans<<endl;
			continue;
		}
		if(n==10){
			int ans=0;
			s1=0;s2=0;s3=0;
			for(int d1=1;d1<=3;d1++){
				for(int d2=1;d2<=3;d2++){
					for(int d3=1;d3<=3;d3++){
						for(int d4=1;d4<=3;d4++){
							for(int d5=1;d5<=3;d5++){
								for(int d6=1;d6<=3;d6++){
									for(int d7=1;d7<=3;d7++){
										for(int d8=1;d8<=3;d8++){
											for(int d9=1;d9<=3;d9++){
												for(int d10=1;d10<=3;d10++){
													s1=0;s2=0;s3=0;
													ddd(d1);ddd(d2);ddd(d3);ddd(d4);ddd(d5);ddd(d6);
													ddd(d7);ddd(d8);ddd(d9);ddd(d10);
													if(s1>n/2||s2>n/2||s3>n/2){
														continue;
													}
													ans=max(ans,(b[1][d1]+b[2][d2]+b[3][d3]+b[4][d4]+b[5][d5]+b[6][d6]+b[7][d7]+b[8][d8]+b[9][d9]+b[10][d10]));
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
			cout<<ans<<endl;
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=max(b[i][1],max(b[i][2],b[i][3]));
		}
		cout<<ans<<endl;
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;

struct cy{
							int m1,m2,m3,c1,c2,c3;
};cy a[10005];

bool cmp(cy x,cy y){
					return max(x.c1,max(x.c2,x.c3))>=max(y.c1,max(y.c2,y.c3));
}

int main(){
				freopen("club.in","r",stdin);
				freopen("club.out","w",stdout);
				int t;
				cin>>t;
				while(t--){
								int n,cnt=0,cnt1=0,cnt2=0,cnt3=0,x;
								cin>>n;
								if(n/2==n/2.0) x=n/2;
								else x=n/2+1;
								for(int i=1;i<=n;i++){
								    cin>>a[i].m1>>a[i].m2>>a[i].m3;
								    if(a[i].m1==max(a[i].m1,max(a[i].m2,a[i].m3))){
																if(a[i].m2>a[i].m3){
																				a[i].c1=a[i].m1-a[i].m2;
																				a[i].c2=a[i].m3-a[i].m3;
																				a[i].c3=0;
																}
																else{
																	   a[i].c1=a[i].m1-a[i].m3;
																				a[i].c2=0;
																				a[i].c3=a[i].m3-a[i].m2;
																}
												}
												else if(a[i].m2==max(a[i].m1,max(a[i].m2,a[i].m3))){
																if(a[i].m1>a[i].m3){
																				a[i].c1=a[i].m1-a[i].m3;
																				a[i].c2=a[i].m2-a[i].m1;
																				a[i].c3=0;
																}
																else{
																	   a[i].c1=0;
																				a[i].c2=a[i].m2-a[i].m3;
																				a[i].c3=a[i].m3-a[i].m1;
																}
												}
												else{
																if(a[i].m1>a[i].m2){
																				a[i].c1=a[i].m1-a[i].m2;
																				a[i].c2=0;
																				a[i].c3=a[i].m3-a[i].m1;
																}
																else{
																	   a[i].c1=0;
																				a[i].c2=a[i].m2-a[i].m1;
																				a[i].c3=a[i].m3-a[i].m2;
																}
												}
								}
								sort(a+1,a+n+1,cmp);
								for(int i=1;i<=n;i++){
												if(a[i].m1==max(a[i].m1,max(a[i].m2,a[i].m3)) and cnt1<x){
																cnt+=a[i].m1;
																cnt1++;
												}
												else if(a[i].m2==max(a[i].m2,a[i].m3) and cnt2<x){
																cnt+=a[i].m2;
																cnt2++;
												}
												else{
													   if(cnt3<x){
		   											    cnt+=a[i].m3;
															    	cnt3++;
																}
																else{
																				if(a[i].m1==max(a[i].m1,a[i].m2) and cnt1<x){
																						  cnt+=a[i].m1;
																					  	cnt1++;
															  			}
																				else{
																			     cnt+=a[i].m2;
																				   	cnt2++;
																    }
																}
												}
								}
								cout<<cnt<<endl;
				}
				return 0;
}

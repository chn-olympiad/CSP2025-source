#include<bits/stdc++.h>
using namespace std;
struct node{
	int value;
	int id;
};
node xxx[100005];
node yyy[100005];
node zzz[100005];
node minn1,minn2,minn3;
int T,n,ans;
int a[100005][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		minn1.value=1e5;
		minn2.value=1e5;
		minn3.value=1e5;
		int average=n/2,g[3]={0,0,0};
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				xxx[i].value=a[i][0]; xxx[i].id=0;
				if(a[i][1]>=a[i][2]){
					yyy[i].value=a[i][1]; yyy[i].id=1;
					zzz[i].value=a[i][2]; zzz[i].id=2;
				}
				else{
					yyy[i].value=a[i][2]; yyy[i].id=2;
					zzz[i].value=a[i][1]; zzz[i].id=1;
				}
			}
			else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				xxx[i].value=a[i][1]; xxx[i].id=1;
				if(a[i][0]>=a[i][2]){
					yyy[i].value=a[i][0]; yyy[i].id=0;
					zzz[i].value=a[i][2]; zzz[i].id=2;
				}
				else{
					yyy[i].value=a[i][2]; yyy[i].id=2;
					zzz[i].value=a[i][0]; zzz[i].id=0;
				}
			}
			else if(a[i][2]>=a[i][0]&&a[i][2]>=a[i][1]){
				xxx[i].value=a[i][2]; xxx[i].id=2;
				if(a[i][0]>=a[i][1]){
					yyy[i].value=a[i][0]; yyy[i].id=0;
					zzz[i].value=a[i][1]; zzz[i].id=1;
				}
				else{
					yyy[i].value=a[i][1]; yyy[i].id=1;
					zzz[i].value=a[i][0]; zzz[i].id=0;
				}
			}
		} 
		for(int i=1;i<=n;i++){
//			cout<<ans<<" ";
			if(g[xxx[i].id]+1<=average){
				if(xxx[i].id==0){
					if(xxx[i].value<minn1.value){
						minn1.value=xxx[i].value;
						minn1.id=i;
					}
				} else if(xxx[i].id==1){
					if(xxx[i].value<minn2.value){
						minn2.value=xxx[i].value;
						minn2.id=i;
					}
				} else if(xxx[i].id==2){
					if(xxx[i].value<minn3.value){
						minn3.value=xxx[i].value;
						minn3.id=i;
					}
				} 
				g[xxx[i].id]++;
				ans+=xxx[i].value;
			} else{
				if(xxx[i].id==0){
					int s1=yyy[minn1.id].value+xxx[i].value;
					int s2=minn1.value+yyy[i].value;
					if(s1>s2){
						g[yyy[i].id]++;
						ans-=minn1.value;
						ans+=yyy[minn1.id].value;
						ans+=xxx[i].value;
						if(yyy[minn1.id].id==0)
							if(yyy[minn1.id].value<minn1.value)
								minn1.value=yyy[minn1.id].value;
						else if(yyy[minn1.id].id==1)
							if(yyy[minn1.id].value<minn2.value)
								minn2.value=yyy[minn1.id].value;
						else if(yyy[minn1.id].id==2)
							if(yyy[minn1.id].value<minn3.value)
								minn3.value=yyy[minn1.id].value;					
					} else{
						ans+=yyy[i].value;
						g[yyy[i].id]++;
						if(yyy[i].id==0){
							if(yyy[i].value<minn1.value){
								minn1.value=yyy[i].value;
								minn1.id=i;
							}
						} else if(yyy[i].id==1){
							if(yyy[i].value<minn2.value){
								minn2.value=yyy[i].value;
								minn2.id=i;
							}
						} else if(yyy[i].id==2){
							if(yyy[i].value<minn3.value){
								minn3.value=yyy[i].value;
								minn3.id=i;
							}
						} 
					} 
				} else if(xxx[i].id==1){
					int s1=yyy[minn2.id].value+xxx[i].value;
					int s2=minn2.value+yyy[i].value;
					if(s1>s2){
						g[yyy[i].id]++;
						ans-=minn2.value;
						ans+=yyy[minn2.id].value;
						ans+=xxx[i].value;
						if(yyy[minn2.id].id==0)
							if(yyy[minn2.id].value<minn1.value)
								minn1.value=yyy[minn2.id].value;
						else if(yyy[minn2.id].id==1)
							if(yyy[minn2.id].value<minn2.value)
								minn2.value=yyy[minn2.id].value;
						else if(yyy[minn2.id].id==2)
							if(yyy[minn2.id].value<minn3.value)
								minn3.value=yyy[minn2.id].value;	
					} else{
						ans+=yyy[i].value;
						g[yyy[i].id]++;
						if(yyy[i].id==0){
							if(yyy[i].value<minn1.value){
								minn1.value=yyy[i].value;
								minn1.id=i;
							}
						} else if(yyy[i].id==1){
							if(yyy[i].value<minn2.value){
								minn2.value=yyy[i].value;
								minn2.id=i;
							}
						} else if(yyy[i].id==2){
							if(yyy[i].value<minn3.value){
								minn3.value=yyy[i].value;
								minn3.id=i;
							}
						} 
					}
				}  else if(xxx[i].id==2){
					int s1=yyy[minn3.id].value+xxx[i].value;
					int s2=minn3.value+yyy[i].value;
					if(s1>s2){
						g[yyy[i].id]++;
						ans-=minn3.value;
						ans+=yyy[minn3.id].value;
						ans+=xxx[i].value;
						if(yyy[minn3.id].id==0)
							if(yyy[minn3.id].value<minn1.value)
								minn1.value=yyy[minn3.id].value;
						else if(yyy[minn3.id].id==1)
							if(yyy[minn3.id].value<minn2.value)
								minn2.value=yyy[minn3.id].value;
						else if(yyy[minn3.id].id==2)
							if(yyy[minn3.id].value<minn3.value)
								minn3.value=yyy[minn3.id].value;	
					} else{
						ans+=yyy[i].value;
						g[yyy[i].id]++;
						if(yyy[i].id==0){
							if(yyy[i].value<minn1.value){
								minn1.value=yyy[i].value;
								minn1.id=i;
							}
						} else if(yyy[i].id==1){
							if(yyy[i].value<minn2.value){
								minn2.value=yyy[i].value;
								minn2.id=i;
							}
						} else if(yyy[i].id==2){
							if(yyy[i].value<minn3.value){
								minn3.value=yyy[i].value;
								minn3.id=i;
							}
						} 
					}
				}
			}				
		}
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
	return 0;
}

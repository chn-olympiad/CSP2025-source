#include<bits/stdc++.h>
using namespace std;
int T,n;
struct st{
	int one;
	int two;
	int three;
	int fst[3];
	int snd[3];
	int trd[3];
}a[234567];
int ans1,ans2,ans3,a1,a2,a3,f1,f2,f3;
bool cmp(st xx,st yy){
	if(xx.fst[1]!=yy.fst[1]){
		return xx.fst[1]>yy.fst[1];
	}if(xx.snd[1]!=yy.snd[1]){
		return xx.snd[1]>yy.snd[1];
	}return xx.trd[1]>yy.trd[1];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;ans1=0;ans2=0;ans3=0;a1=0;a2=0;a3=0;f1=0;f2=0;f3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].one>>a[i].two>>a[i].three;
			if(a[i].one>=a[i].two&&a[i].one>=a[i].three){
				a[i].fst[1]=a[i].one;a[i].fst[2]=1;
				f1++;
				if(a[i].two>=a[i].three){
					a[i].snd[1]=a[i].two;a[i].snd[2]=2;
					a[i].trd[1]=a[i].three;a[i].trd[2]=3;
				}else{
					a[i].snd[1]=a[i].three;a[i].snd[2]=3;
					a[i].trd[1]=a[i].two;a[i].trd[2]=2;
				}
			}
			//222222222222222222222222222222222222222
			else if(a[i].two>=a[i].one&&a[i].two>=a[i].three){
				f2++;
				a[i].fst[1]=a[i].two;a[i].fst[2]=2;
				if(a[i].one>=a[i].three){
					a[i].snd[1]=a[i].one;a[i].snd[2]=1;
					a[i].trd[1]=a[i].three;a[i].trd[2]=3;
				}else{
					a[i].snd[1]=a[i].three;a[i].snd[2]=3;
					a[i].trd[1]=a[i].one;a[i].trd[2]=1;
				}
			}
			//3333333333333333333333333333333333333333
			else if(a[i].three>=a[i].two&&a[i].three>=a[i].one){
				f3++;
				a[i].fst[1]=a[i].three;a[i].fst[2]=3;
				if(a[i].one>=a[i].two){
					a[i].snd[1]=a[i].one;a[i].snd[2]=1;
					a[i].trd[1]=a[i].two;a[i].trd[2]=2;
				}else{
					a[i].snd[1]=a[i].two;a[i].snd[2]=2;
					a[i].trd[1]=a[i].one;a[i].trd[2]=1;
				}
			}
		}
		
		if(n==2){
			if(a[1].fst[2]!=a[2].fst[2]){
				cout<<a[1].fst[1]+a[2].fst[1]<<endl;
				continue;
			}else{
				cout<<max(a[1].fst[1]+a[2].snd[1],a[1].snd[1]+a[2].fst[1])<<endl;
				continue;
			}
			
		}
		sort(a+1,a+1+n,cmp);
		f1-=n/2;
		f2-=n/2;
		f3-=n/2;
		cout<<f1<<' '<<f2<<' '<<f3<<"<<f"<<endl;
		for(int i=1;i<=n;i++){
			if(a[i].fst[2]==1&&a1<n/2){
				if((n/2-a1)<=f1){
					f1--;
					for(int j=i+1;j<=n;j++){
						if(a[j].fst[1]<a[i].snd[1]&&a[j].fst[2]==1){
							swap(a[i],a[j]);
							swap(a[j].fst,a[j].snd);
							swap(a[j].snd,a[j].trd);
							a[j].trd[1]=0;a[j].trd[2]=1;
							//cout<<"jiaohuanle"<<i<<' '<<j<<"   ";
						}
					}
				}
				if(a1<n/2){
					a1++;
					ans1+=a[i].fst[1];
				}
				else if(a[i].snd[2]==2){
					ans2+=a[i].snd[1];
					a2++;
				}else{
					a3++;
					ans3+=a[i].snd[1];
				}
			}
			//22222222222222222222222222222222222222222
			if(a[i].fst[2]==2){
				if((n/2-a2)<f2&&a2<n/2){
					f2--;
					for(int j=i+1;j<=n;j++){
						if(a[j].fst[1]<a[i].snd[1]&&a[j].fst[2]==2){
							swap(a[i],a[j]);
							swap(a[j].fst,a[j].snd);
							swap(a[j].snd,a[j].trd);
							a[j].trd[1]=0;a[j].trd[2]=2;
						}
					}
				}
				if(a2<n/2){
					a2++;
					ans2+=a[i].fst[1];
				}
				else if(a[i].snd[2]==1){
					ans1+=a[i].snd[1];
					a1++;
				}else{
					a3++;
					ans3+=a[i].snd[1];
				}
			}
			//333333333333333333333333333333333333333333
			if(a[i].fst[2]==3){
				if((n/2-a3)<f3&&a3<n/2){
					f3--;
					for(int j=i+1;j<=n;j++){
						if(a[j].fst[1]<a[i].snd[1]&&a[j].fst[2]==3){
							swap(a[i],a[j]);
							swap(a[j].fst,a[j].snd);
							swap(a[j].snd,a[j].trd);
							a[j].trd[1]=0;a[j].trd[2]=3;
						}
					}
				}
				if(a3<n/2){
					a3++;
					ans3+=a[i].fst[1];
				}
				else if(a[i].snd[2]==1){
					ans1+=a[i].snd[1];
					a1++;
				}else{
					a2++;
					ans2+=a[i].snd[1];
				}
			}
			
		}
	cout<<ans1+ans2+ans3<<endl;
	}
	return 0;
}

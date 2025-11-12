#include<bits/stdc++.h>
using namespace std;
int sat1[100001],sat2[100001],sat3[100001],book1[50000],book2[50000],book3[50000],satmax[100001],a1[100001],a2[100001],b1[100001],b2[100001],c1[100001],c2[100001],book[100001];
int main(){
	freopen("club","r",stdin);
	freopen("club","w",stdout);
	int n,t,ans=0,bok1=0,bok2=0,bok3=0,m=0,mem=0;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		ans=0;
		bok1=0;
		bok2=0;
		bok3=0;
		m=0;
		mem=0;
		for(int s=0;s<n;s++){
			book[s]=0;
		}
		for(int s=0;s<n;s++){
			int f;
			cin>>sat1[s]>>sat2[s]>>sat3[s];
			f=max(sat1[s],sat2[s]);
			satmax[s]=max(f,sat3[s]);
		}
		mem=bok1+bok2+bok3;
		int j=0;
		while(bok1<n/2&&bok2<n/2&&bok3<n/2&&mem<=n){
			if(sat1[j]>=sat2[j]&&sat1[j]>=sat3[j]){
				ans+=sat1[j];
				bok1++;
				book1[bok1]=sat1[j];
				a1[bok1]=sat2[j];
				a2[bok1]=sat3[j];
			}
			if(sat2[j]>=sat1[j]&&sat2[j]>=sat3[j]){
				ans+=sat2[j];
				bok2++;
				book2[bok2]=sat2[j];
				b1[bok2]=sat1[j];
				b2[bok2]=sat3[j];
			}
			if(sat3[j]>=sat2[j]&&sat3[j]>=sat1[j]){
				ans+=sat3[j];
				bok3++;
				book3[bok3]=sat3[j];
				c1[bok3]=sat1[j];
				c2[bok3]=sat2[j];
			}
			j++;
			m++;
		}
		for(int j=m;j<n;j++){
			if(bok1==n/2){
				if(satmax[j]==sat1[j]){
					//int l;
					//for(int p=2;p<=bok1;p++){
					//	l=min(book1[p],book1[p-1]);
					//}
					//if(satmax[j]>=l){
						int g[50000],e=0;
						
						for(int p=1;p<j;p++){
									for(int h=1;h<j+1;h++){
										if(p==book[h]){
							continue;
						}
							if(satmax[j]+max(a1[p],a2[p])>book1[p]+max(sat2[j],sat3[j])){
							g[p]=satmax[j]+max(a1[p],a2[p])-book1[p];
							e=max(e,g[p]);
							}
						}
						for(int p=1;p<j;p++){
							if(e==g[p]){
							book[j]=p;
							}
						}
						if(e==0){
							ans+=max(sat2[j],sat3[j]);
						}
						else ans+=e;
					//}
			
				else{
					ans+=satmax[j];
			}			
			}
		}
			else if(bok2==n/2){
				if(satmax[j]==sat2[j]){
					//int l;
					//for(int p=2;p<=bok2;p++){
					//	l=min(book2[p],book2[p-1]);
					//}
					//if(satmax[j]>=l){
						int g[50000],e=0;
						for(int p=1;p<j;p++){
							for(int h=1;h<j+1;h++){
							if(p==book[h]){
							continue;
						}
							if(satmax[j]+max(b1[p],b2[p])>book2[p]+max(sat1[j],sat3[j])){
							g[p]=satmax[j]+max(b1[p],b2[p])-book2[p];
							e=max(e,g[p]);
							}
							}
							
						}
						for(int p=1;p<j;p++){
							if(e==g[p]){
							book[j]=p;
							}
						}
						if(e==0){
							ans+=max(sat1[j],sat3[j]);
						}
						else ans+=e;
					//}
			}
				else{
					ans+=satmax[j];
			}
			}
			else if(bok3==n/2){
				if(satmax[j]==sat3[j]){
					//int l;
					//for(int p=2;p<=bok3;p++){
					//	l=min(book3[p],book3[p-1]);
					//}
					//if(satmax[j]>=l){
						int g[50000],e=0;
						for(int p=1;p<j;p++){
							for(int h=1;h<j+1;h++){
							if(p==book[h]){
							continue;
							}
						
							if(satmax[j]+max(c1[p],c2[p])>book3[p]+max(sat1[j],sat2[j])){
							g[p]=satmax[j]+max(c1[p],c2[p])-book3[p];
							e=max(e,g[p]);
							}
						}
						}
						if(e==0){
							ans+=max(sat1[j],sat2[j]);
						}
						else ans+=e;
						//cout<<e<<endl;
					//}
			}
				else{
					ans+=satmax[j];
			}			
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

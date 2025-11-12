#include<bits/stdc++.h>
using namespace std;
int a1[114514],a2[114514],a3[114514];
int l1f,l2f,l3f,p1,p2,p3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,sum=0;
	cin>>t;
	for(int iii=1;iii<=t;iii++){
		int n;
		cin>>n;
		l1f=l2f=l3f=n;
		p1=p2=p3=0;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			a1[i]=a1[i]*100001+i;
			a2[i]=a2[i]*100001+i;
			a3[i]=a3[i]*100001+i;
		}
		sort(a1+1,a1+n+1);
		sort(a2+1,a2+n+1);
		sort(a3+1,a3+n+1);
	
		for(int i=1;i<=n;i++){
			while(a1[l1f]==-1)l1f--;
			while(a2[l2f]==-1)l2f--;
			while(a3[l3f]==-1)l3f--;
			///////////////////
			if(a1[l1f]>=max(a2[l2f],a3[l3f]) && p1<n/2){
				p1++;
				//cout<<a1[l1f]<<" "<<a2[l2f]<<" "<<a3[l3f]<<" "<<"A"<<l1f<<" "<<l2f<<" "<<l3f<<endl;
				l1f--;
				sum+=a1[l1f+1]/100001;
				//cout<<a1[l1f+1]%100001<<"  ";
				for(int j=1;j<=n;j++){
					if(a2[j]%100001==a1[l1f+1]%100001){
						//cout<<a2[j]<<" ";
						a2[j]=-1;
					}
					if(a3[j]%100001==a1[l1f+1]%100001){
						//cout<<a3[j]<<" ";
						a3[j]=-1;
					}
				}
				//cout<<endl;
				continue;
			}
			///////////////////
			if(a2[l2f]>=max(a1[l1f],a3[l3f]) && p2<n/2){
				p2++;
				//cout<<a1[l1f]<<" "<<a2[l2f]<<" "<<a3[l3f]<<" "<<"B"<<l1f<<" "<<l2f<<" "<<l3f<<endl;
				l2f--;
				sum+=a2[l2f+1]/100001;
				//cout<<a2[l2f+1]%100001<<"  ";
				for(int j=1;j<=n;j++){
					if(a1[j]%100001==a2[l2f+1]%100001){
						//cout<<a1[j]<<" ";
						a1[j]=-1;
					}
					if(a3[j]%100001==a2[l2f+1]%100001){
						//cout<<a3[j]<<" ";
						a3[j]=-1;
					}
				}
				//cout<<endl;
				continue;
			}
			///////////////////
			if(a3[l3f]>=max(a1[l1f],a2[l2f]) && p3<n/2){
				p3++;
				//cout<<a1[l1f]<<" "<<a2[l2f]<<" "<<a3[l3f]<<" "<<"C"<<l1f<<" "<<l2f<<" "<<l3f<<endl;
				//cout<<a3[l3f+1]%100001<<"  ";
				l3f--;
				sum+=a3[l3f+1]/100001;
				for(int j=1;j<=n;j++){
					if(a1[j]%100001==a3[l3f+1]%100001){
						//cout<<a1[j]<<" ";
						a1[j]=-1;
					}
					if(a2[j]%100001==a3[l3f+1]%100001){
						//cout<<a2[j]<<" ";
						a2[j]=-1;
					}
				}
				//cout<<endl;
				continue;
			}
			///////////////////
			if(p1>=n/2)for(int j=l1f;j>=1;j--)a1[j]=-2;
			if(p1>=n/2)for(int j=l2f;j>=1;j--)a2[j]=-2;
			if(p1>=n/2)for(int j=l3f;j>=1;j--)a3[j]=-2;
			
//			cout<<endl<<endl<<endl;
//			for(int ii=1;ii<=n;ii++)cout<<a1[ii]<<" ";
//			cout<<endl;
//			for(int ii=1;ii<=n;ii++)cout<<a2[ii]<<" ";
//			cout<<endl;
//			for(int ii=1;ii<=n;ii++)cout<<a3[ii]<<" ";
//			cout<<endl<<endl<<endl;
		}
		cout<<sum<<endl;
		sum=0;
	}
	return 0;
}

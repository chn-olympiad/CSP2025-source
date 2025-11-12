#include<bits/stdc++.h>
using namespace std;

 int n,x,y,z,t;
 const int N=100010;
 vector<int>help;
  int num[N];
 int a[N],b[N],c[N],big[N],small[N],mid[N];
 int Big=0;
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int main(){
	cin>>t;
	for(int k=0;k<t;k++){
		num[k]=0;
		cin>>n;
		int A=n/2,B=n/2,C=n/2;

	//put
	for(int i=0;i<n;i++){
		cin>>x>>y>>z;
		num[k]+=min(x,min(y,z));
		a[i]=x-min(x,min(y,z));
		b[i]=y-min(x,min(y,z));
		c[i]=z-min(x,min(y,z));
		big[i]=max(a[i],max(b[i],c[i]));
		small[i]=min(a[i],min(b[i],c[i]));
		mid[i]=a[i]+b[i]+c[i]-big[i]-small[i];
	}
	//maxsort
	for(int i=0;i<n;i++){
		Big=i;
		for(int j=i;j<n;j++){
			Big=big[Big]>big[j]?Big:j;
		}swap(big[i],big[Big]);
		swap(mid[i],mid[Big]);
		swap(small[i],small[Big]);
		swap(a[i],a[Big]);
		swap(b[i],b[Big]);
		swap(c[i],c[Big]);}
	//choose
	for(int i=0;i<n;i++){

		if(big[i]==a[i]&&A>0){
			A--;
			num[k]+=big[i];

		}else if(big[i]==b[i]&&B>0){
			B--;
			num[k]+=big[i];
		}else if(big[i]==c[i]&&C>0){
			C--;
			num[k]+=big[i];
		}else{
			big[i]=mid[i];
			i--;
			if(i+1<n&&big[i]<big[i+1]){
				for(int j=i;j<n;j++){
				if(big[i]<big[j])swap(big[i],big[j]);
			}
			}

		}

	}

	}
	for(int i=0;i<t;i++){
		cout<<num[i]<<endl;
	}
	return 0;
}

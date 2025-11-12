#include<bits/stdc++.h>
using namespace std;
int oc[4][200001],c[200001];
struct str{
	int ok[4],joi;
}a[200001];
int minn(int a,int b,int c){
	if(a<=b&&a<=c)return a;
	if(b<=a&&b<=c)return b;
	if(c<=a&&c<=b)return c;
}
int maxx(int a,int b,int c){
	if(a>=b&&a>=c)return a;
	if(b>=a&&b>=c)return b;
	if(c>=a&&c>=b)return c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t,n,m[4],i,j,k;
	long long num;
	cin>>t;
	while(t--){
		for(i=1;i<=200000;i++)
		  c[i]=1e9;
		m[1]=0;
		m[2]=0;
		m[3]=0;
		num=0;
	    cin>>n;
	    for(i=1;i<=3;i++)
	      for(j=1;j<=200000;j++)
	        oc[i][j]=0;
	    for(i=1;i<=n;i++)
	      for(j=1;j<=3;j++)
	        cin>>a[i].ok[j];
	    for(i=1;i<=n;i++){
		    if(a[i].ok[1]>=a[i].ok[2]&&a[i].ok[1]>=a[i].ok[3]){
		    	oc[1][++m[1]]=i;
		    	a[i].joi=1;
		    	num+=a[i].ok[1];
			}
		    else if(a[i].ok[2]>=a[i].ok[1]&&a[i].ok[2]>=a[i].ok[3]){
		    	oc[2][++m[2]]=i;
		    	a[i].joi=2;
		    	num+=a[i].ok[2];
			}
		    else if(a[i].ok[3]>=a[i].ok[1]&&a[i].ok[3]>=a[i].ok[2]){
		    	oc[3][++m[3]]=3;
				a[i].joi=3; 
				num+=a[i].ok[3];
			}
	    }
		/*for(i=1;i<=n;i++)
		  cout<<"i: "<<i<<" "<<a[i].joi;
		cout<<endl;	*/
	    if((m[1]<=(n/2)&&m[2]<=(n/2))&&m[3]<=(n/2)){
	    	cout<<num<<endl;
	    	continue;
		}
		//cout<<m[1]<<" "<<m[2]<<" "<<m[3]<<" "<<endl;
		//cout<<num<<endl;
	    if(m[1]>=m[2]&&m[1]>=m[3])j=1;
	    else if(m[2]>=m[1]&&m[2]>=m[3])j=2;
	    else j=3;
	    int cha,sum;
	    if(j==3)cha=m[3]-(n/2);
	    else if(j==2)cha=m[2]-(n/2);
	    else if(j==1)cha=m[1]-(n/2);
	    //cout<<cha<<endl;
		for(i=1;i<=n;i++){
			if(a[i].joi!=j)continue;
			for(k=1;k<=3;k++){
		  	    if(k!=j)c[i]=min(c[i],abs(a[i].ok[j]-a[i].ok[k]));
		    }
		} 
		sort(c+1,c+n+1);
		for(i=1;i<=cha;i++)
		  num-=c[i];
		cout<<num<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int T,a[100005][5],mx[100005][5],c_1[100005],c_2[100005],c_3[100005],ans,z[100005],b[5];
int main()
{
	//我是浦帅的忠实粉丝 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
    while(T--){
    	memset(mx,0,sizeof(mx));
    	memset(a,0,sizeof(a));
    	memset(c_1,0,sizeof(c_1));
    	memset(c_2,0,sizeof(c_2));
    	memset(c_3,0,sizeof(c_3));
    	memset(z,0,sizeof(z));
    	memset(b,0,sizeof(b));
    	ans=0;
		int n,cnt1=0,cnt2=0,cnt3=0;
    	cin>>n;
    	for(int i=1;i<=n;i++){
    		cin>>a[i][1]>>a[i][2]>>a[i][3];
    		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
    			mx[i][1]=a[i][1];
    			z[i]=1;
    			if(a[i][2]>a[i][3]){
    				c_1[++cnt1]=a[i][1]-a[i][2];
    				mx[i][2]=a[i][2];
				}else{
					mx[i][2]=a[i][3];
					c_1[++cnt1]=a[i][1]-a[i][3];
				}
			}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				mx[i][1]=a[i][2];
				z[i]=2;
    			if(a[i][1]>a[i][3]){
    				c_2[++cnt2]=a[i][2]-a[i][1];
    				mx[i][2]=a[i][1];
				}else{
					mx[i][2]=a[i][3];
					c_2[++cnt2]=a[i][2]-a[i][3];
				}
			}else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
				mx[i][1]=a[i][3];
				z[i]=3;
    			if(a[i][1]>a[i][2]){
    				c_3[++cnt3]=a[i][3]-a[i][1];
    				mx[i][2]=a[i][1];
				}else{
					mx[i][2]=a[i][2];
					c_3[++cnt3]=a[i][3]-a[i][2];
				}
			}
		}
//		cout<<endl;
//		int c1=0,c2=0,c3=0;
//		for(int i=1;i<=n;i++){
//			cout<<mx[i][1]<<" "<<z[i]<<" ";
//			if(z[i]==1) cout<<c_1[++c1]<<endl;
//			if(z[i]==2) cout<<c_2[++c2]<<endl;
//			if(z[i]==3) cout<<c_3[++c3]<<endl;
//		}
        int m=n/2;
        sort(c_1+1,c_1+cnt1+1);
        sort(c_2+1,c_2+cnt2+1);
  		sort(c_3+1,c_3+cnt3+1);
  		cnt1=0,cnt2=0,cnt3=0;
    	for(int i=1;i<=n;i++){
    		ans+=mx[i][1];
    		b[z[i]]++;
    		if(b[1]>m){
    			b[1]=m;
    		    ans-=c_1[++cnt1];	
			}
			if(b[2]>m){
				b[2]=m;
			    ans-=c_2[++cnt2];	
			}
			if(b[3]>m){
				b[3]=m;
				ans-=c_3[++cnt3];
			}
		}
		
		cout<<ans<<endl;
	}
	return 0;
} 
/*

1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926


147325
*/

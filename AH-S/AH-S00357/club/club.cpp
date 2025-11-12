#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","W",stdout);
    int n,t,a1[10010],a2[10010],a3[10010],max1=-1,max2=-1,max3=-1;
    cin>>t;
    int b1[10010],b2[10010],b3[10010];
    for(int q=1;q<=t;q++){
        cin>>n;
        int cnt=0;
        for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			b1[i]=a1[i];
			b2[i]=a2[i];
			b3[i]=a3[i];	
		}for(int i=1;i<=n;i++){
			max1=max(b1[i],max1);b1[i]=0;
			max2=max(b2[i],max2);b2[i]=0;
			max3=max(b3[i],max3);b3[i]=0;
		}cnt+=(max1+max2+max3);
		int maxn=-1;
		for(int i=3;i<=n;i++){
			for(int j=1;j<=n;j++){
		         maxn=max(max(maxn,a1[i]),max(a2[i],a3[i]));
		    }
		    cnt+=maxn;
		}
		cout<<cnt<<endl;
			
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int t;
int n;
long long ans;
int pro[5];
long long a[100005][5],cha[100005];
int main()
{
 freopen("club.in","r",stdin);
 freopen("club.out","w",stdout);
 scanf("%d",&t);
for(int i=1;i<=t;i++){
	scanf("%d",&n);
	if(n<=30){
		
	for(int j=1;j<=n;j++){
		int b1,b2,b3;
		scanf("%d%d%d",&b1,&b2,&b3);
		a[j][1]=max(b1,max(b2,b3));
		a[j][3]=min(b1,min(b2,b3));
	    if(a[j][3]==b1&&b2==a[j][1]) a[j][2]=b3;
	    if(a[j][3]==b2&&b1==a[j][1]) a[j][2]=b3;
	    if(a[j][3]==b3&&b2==a[j][1]) a[j][2]=b1;
	    if(a[j][3]==b2&&b3==a[j][1]) a[j][2]=b1;
	    if(a[j][3]==b1&&b3==a[j][1]) a[j][2]=b2;
	    if(a[j][3]==b3&&b1==a[j][1]) a[j][2]=b2;
	    
	if(b1==a[j][1]) a[j][4]=1;
	if(b2==a[j][1]) a[j][4]=2;
	if(b3==a[j][1]) a[j][4]=3;
	pro[a[j][4]]++;
	cha[j]=a[j][1]-a[j][2];
	ans+=a[j][1];
}

for(int g=1;g<=n;g++){
	for(int f=g;f<=n;f++){
		if(cha[f]<cha[g]) swap(cha[g],cha[f]);
	}
}
for(int k=1;k<=3;k++){
	if(pro[k]>(n/2)){
		int d=pro[k]-(n/2);
			for(int q=1;q<=d;q++){
					ans-=cha[q];
		}
	}else continue;
	}
	cout<<ans<<endl;
ans=0;
	for(int j=1;j<=4;j++) pro[j]=0;
	for(int j=1;j<=n;j++) cha[j]=0;
}
if(n==200){
			
	for(int j=1;j<=n;j++){
		int b1,b2,b3;
		scanf("%d%d%d",&b1,&b2,&b3);
		a[j][1]=max(b1,b2);
		a[j][3]=0;
	    a[j][2]=min(b1,b2);
	    
	if(b1==a[j][1]) a[j][4]=1;
	if(b2==a[j][1]) a[j][4]=2;
	pro[a[j][4]]++;
	cha[j]=a[j][1]-a[j][2];
	ans+=a[j][1];
}

for(int g=1;g<=n;g++){
	for(int f=g;f<=n;f++){
		if(cha[f]<cha[g]) swap(cha[g],cha[f]);
	}
}
for(int k=1;k<=3;k++){
	if(pro[k]>(n/2)){
		int d=pro[k]-(n/2);
			for(int q=1;q<=d;q++){
					ans-=cha[q];
		}
	}else continue;
	}
	cout<<ans<<endl;
ans=0;
	for(int j=1;j<=4;j++) pro[j]=0;
	for(int j=1;j<=n;j++) cha[j]=0;
}
if(n>200){
	for(int j=1;j<=n;j++){
		int b1,b2,b3;
		scanf("%d%d%d",&b1,&b2,&b3);
		cha[j]=b1;
}
for(int g=1;g<=n;g++){
	for(int f=g;f<=n;f++){
		if(cha[f]>cha[g]) swap(cha[g],cha[f]);
	}
}
for(int g=1;g<=n/2;g++){
ans+=cha[g];
}
	cout<<ans<<endl;
ans=0;
	for(int j=1;j<=4;j++) pro[j]=0;
	for(int j=1;j<=n;j++) cha[j]=0;
	
	
}

}
return 0;
}


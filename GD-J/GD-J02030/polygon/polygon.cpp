#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int q[N],ans=0;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>q[i];
	}
	sort(q+1,q+n+1);
	int ans=0;
	for(int a=1;a<=n;a++)
	for(int b=a+1;b<=n;b++)
	for(int c=b+1;c<=n;c++){
		if(q[a]+q[b]>q[c])ans++;
	}
	//Èý±ß 
	for(int a=1;a<=n;a++)
	for(int b=a+1;b<=n;b++)
	for(int c=b+1;c<=n;c++)
	for(int d=c+1;d<=n;d++){
		if(q[a]+q[b]+q[c]>q[d])ans++;
	}
	//ËÄ±ß 
	for(int a=1;a<=n;a++)
	for(int b=a+1;b<=n;b++)
	for(int c=b+1;c<=n;c++)
	for(int d=c+1;d<=n;d++)
	for(int e=d+1;e<=n;e++){
		if(q[a]+q[b]+q[c]+q[d]>q[e])ans++;
	}
	//Îå±ß
	for(int a=1;a<=n;a++)
	for(int b=a+1;b<=n;b++)
	for(int c=b+1;c<=n;c++)
	for(int d=c+1;d<=n;d++)
	for(int e=d+1;e<=n;e++)
	for(int f=e+1;f<=n;f++){
		if(q[a]+q[b]+q[c]+q[d]+q[e]>q[f])ans++;
	}
	//Áù±ß
	for(int a=1;a<=n;a++)
	for(int b=a+1;b<=n;b++)
	for(int c=b+1;c<=n;c++)
	for(int d=c+1;d<=n;d++)
	for(int e=d+1;e<=n;e++)
	for(int f=e+1;f<=n;f++)
	for(int g=f+1;g<=n;g++){	
		if(q[a]+q[b]+q[c]+q[d]+q[e]+q[f]>q[g])ans++;
	}
	//Æß±ß
	for(int a=1;a<=n;a++)
	for(int b=a+1;b<=n;b++)
	for(int c=b+1;c<=n;c++)
	for(int d=c+1;d<=n;d++)
	for(int e=d+1;e<=n;e++)
	for(int f=e+1;f<=n;f++)
	for(int g=f+1;g<=n;g++)
	for(int h=g+1;h<=n;h++){	
		if(q[a]+q[b]+q[c]+q[d]+q[e]+q[f]+q[g]>q[h])ans++;
	}
	//°Ë±ß
	for(int a=1;a<=n;a++)
	for(int b=a+1;b<=n;b++)
	for(int c=b+1;c<=n;c++)
	for(int d=c+1;d<=n;d++)
	for(int e=d+1;e<=n;e++)
	for(int f=e+1;f<=n;f++)
	for(int g=f+1;g<=n;g++)
	for(int h=g+1;h<=n;h++)
	for(int i=h+1;i<=n;i++){	
		if(q[a]+q[b]+q[c]+q[d]+q[e]+q[f]+q[g]+q[h]>q[i])ans++;
	}
	//¾Å±ß
	for(int a=1;a<=n;a++)
	for(int b=a+1;b<=n;b++)
	for(int c=b+1;c<=n;c++)
	for(int d=c+1;d<=n;d++)
	for(int e=d+1;e<=n;e++)
	for(int f=e+1;f<=n;f++)
	for(int g=f+1;g<=n;g++)
	for(int h=g+1;h<=n;h++)
	for(int i=h+1;i<=n;i++)
	for(int j=i+1;j<=n;j++){	
		if(q[a]+q[b]+q[c]+q[d]+q[e]+q[f]+q[g]+q[h]+q[i]>q[j])ans++;
	}
	//Ê®±ß
	cout<<ans; 
	return 0;
} 

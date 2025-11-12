#include <bits/stdc++.h>
using namespace std;
const int N=5007,mod=998244353;
int n,ans,cnt,mx,a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==1||n==2){
		cout<<"0\n";
		return 0;
	}
	if(n==3){
		for(int i=1;i<=n;i++) cnt+=a[i],mx=max(mx,a[i]);
		if(mx*2<cnt) cout<<"1\n";
		else cout<<"0\n";
		return 0;
	}
	if(n==4){
		cnt=a[1]+a[2]+a[3],mx=max(a[1],a[2]),mx=max(mx,a[3]);
		if(cnt>mx*2) ans=(((ans+1)%mod)+mod)%mod;
		cnt=a[1]+a[2]+a[4],mx=max(a[1],a[2]),mx=max(mx,a[4]);
		if(cnt>mx*2) ans=(((ans+1)%mod)+mod)%mod;
		cnt=a[1]+a[3]+a[4],mx=max(a[1],a[3]),mx=max(mx,a[4]);
		if(cnt>mx*2) ans=(((ans+1)%mod)+mod)%mod;
		cnt=a[2]+a[3]+a[4],mx=max(a[2],a[3]),mx=max(mx,a[4]);
		cnt=a[1]+a[2]+a[3]+a[4],mx=max(a[1],a[2]),mx=max(mx,a[3]),mx=max(mx,a[4]);
		if(cnt>mx*2) ans=(((ans+1)%mod)+mod)%mod;
	}
	if(n==5){
		for(int i=1;i<=n-2;i++)
		for(int j=2;j<=n-1;j++)
		for(int k=3;k<=n;k++){
			if(i>=j||j>=k||i>=k) continue;
			mx=0;
			cnt=a[i]+a[j]+a[k],mx=max(a[i],a[j]),mx=max(mx,a[k]);
			if(cnt>mx*2) ans=(ans+1)%mod;
		}
		for(int b=1;b<=n-3;b++)
		for(int c=2;c<=n-2;c++)
		for(int d=3;d<=n-1;d++)
		for(int e=4;e<=n;e++){
			if(b>=c||b>=d||b>=e||c>=d||c>=e||d>=e) continue;
				mx=0;
				cnt=a[b]+a[c]+a[d]+a[e];
				mx=max(a[b],a[c]),mx=max(mx,a[d]),mx=max(mx,a[e]);
				if(cnt>mx*2) ans=(ans+1)%mod;
			}
		cnt=a[1]+a[2]+a[3]+a[4]+a[5];
		mx=max(a[1],a[2]),mx=max(mx,a[3]),mx=max(mx,a[4]),mx=max(mx,a[5]);
		if(cnt>mx*2) ans=(ans+1)%mod;
	}
	if(n==6){
		for(int i=1;i<=n;i++)
		for(int j=2;j<=n;j++)
		for(int k=3;k<=n;k++){
			if(i>=j||j>=k||i>=k) continue;
				mx=0;
				cnt=a[i]+a[j]+a[k],mx=max(a[i],a[j]),mx=max(mx,a[k]);
				if(cnt>mx*2) ans=(((ans+1)%mod)+mod)%mod;
			}
		for(int b=1;b<=n;b++)
		for(int c=2;c<=n;c++)
		for(int d=3;d<=n;d++)
		for(int e=4;e<=n;e++){
			if(b>=c||b>=d||b>=e||c>=d||c>=e||d>=e) continue;
			mx=0;
			cnt=a[b]+a[c]+a[d]+a[e];
			mx=max(a[b],a[c]),mx=max(mx,a[d]),mx=max(mx,a[e]);
			if(cnt>mx*2) ans=(((ans+1)%mod)+mod)%mod;
		}
		for(int b=1;b<=n;b++)
		for(int c=2;c<=n;c++)
		for(int d=3;d<=n;d++)
		for(int e=4;e<=n;e++)
		for(int f=5;f<=n;f++){
			if(b>=c||b>=d||b>=e||b>=f||c>=d||c>=e||c>=f||d>=e||d>=f||e>=f) continue;
			mx=0;
			cnt=a[b]+a[c]+a[d]+a[e]+a[f];
			mx=max(a[b],a[c]),mx=max(mx,a[d]),mx=max(mx,a[e]);
			mx=max(mx,a[f]);
			if(cnt>mx*2) ans=(((ans+1)%mod)+mod)%mod;
		}
		cnt=a[1]+a[2]+a[3]+a[4]+a[5]+a[6];
		mx=max(a[1],a[2]),mx=max(mx,a[3]),mx=max(mx,a[4]),mx=max(mx,a[5]);
		mx=max(mx,a[6]);
		if(cnt>mx*2) ans=(((ans+1)%mod)+mod)%mod;
	}
	if(n==7){
		for(int i=1;i<=n;i++)
		for(int j=2;j<=n;j++)
		for(int k=3;k<=n;k++){
			if(i>=j||j>=k||i>=k) continue;
				mx=0;
				cnt=a[i]+a[j]+a[k],mx=max(a[i],a[j]),mx=max(mx,a[k]);
				if(cnt>mx*2) ans=(((ans+1)%mod)+mod)%mod;
		}
		for(int b=1;b<=n;b++)
		for(int c=2;c<=n;c++)
		for(int d=3;d<=n;d++)
		for(int e=4;e<=n;e++){
			if(b>=c||b>=d||b>=e||c>=d||c>=e||d>=e) continue;
			mx=0;
			cnt=a[b]+a[c]+a[d]+a[e];
			mx=max(a[b],a[c]),mx=max(mx,a[d]),mx=max(mx,a[e]);
			if(cnt>mx*2) ans=(((ans+1)%mod)+mod)%mod;
		}
		for(int b=1;b<=n;b++)
		for(int c=2;c<=n;c++)
		for(int d=3;d<=n;d++)
		for(int e=4;e<=n;e++)
		for(int f=5;f<=n;f++){
			if(b>=c||b>=d||b>=e||b>=f||c>=d||c>=e||c>=f||d>=e||d>=f||e>=f) continue;
			mx=0;
			cnt=a[b]+a[c]+a[d]+a[e]+a[f];
			mx=max(a[b],a[c]),mx=max(mx,a[d]),mx=max(mx,a[e]);
			mx=max(mx,a[f]);
			if(cnt>mx*2) ans=(((ans+1)%mod)+mod)%mod;
		}
		for(int b=1;b<=n;b++)
		for(int c=2;c<=n;c++)
		for(int d=3;d<=n;d++)
		for(int e=4;e<=n;e++)
		for(int f=5;f<=n;f++)
		for(int g=6;g<=n;g++){
			if(b>=c||b>=d||b>=e||b>=f||b>=g||c>=d||c>=e||c>=f||c>=g||d>=e||d>=f||d>=g||e>=f||e>=g||f>=g) continue;
			mx=0;
			cnt=a[b]+a[c]+a[d]+a[e]+a[f]+a[g];
			mx=max(a[b],a[c]),mx=max(mx,a[d]),mx=max(mx,a[e]);
			mx=max(mx,a[f]),mx=max(mx,a[g]);
			if(cnt>mx*2) ans=(((ans+1)%mod)+mod)%mod;
		}
		cnt=a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7];
		mx=max(a[1],a[2]),mx=max(mx,a[3]),mx=max(mx,a[4]),mx=max(mx,a[5]);
		mx=max(mx,a[6]),mx=max(mx,a[7]);
		if(cnt>mx*2) ans=(((ans+1)%mod)+mod)%mod;
	}
	if(n==8){
		for(int i=1;i<=n;i++)
		for(int j=2;j<=n;j++)
		for(int k=3;k<=n;k++){
			if(i>=j||j>=k||i>=k) continue;
			mx=0;
			cnt=a[i]+a[j]+a[k],mx=max(a[i],a[j]),mx=max(mx,a[k]);
			if(cnt>mx*2) ans=(((ans+1)%mod)+mod)%mod;
		}
		for(int b=1;b<=n;b++)
		for(int c=2;c<=n;c++)
		for(int d=3;d<=n;d++)
		for(int e=4;e<=n;e++){
			if(b>=c||b>=d||b>=e||c>=d||c>=e||d>=e) continue;
			mx=0;
			cnt=a[b]+a[c]+a[d]+a[e];
			mx=max(a[b],a[c]),mx=max(mx,a[d]),mx=max(mx,a[e]);
			if(cnt>mx*2) ans=(((ans+1)%mod)+mod)%mod;
		}
		for(int b=1;b<=n;b++)
		for(int c=2;c<=n;c++)
		for(int d=3;d<=n;d++)
		for(int e=4;e<=n;e++)
		for(int f=5;f<=n;f++){
			if(b>=c||b>=d||b>=e||b>=f||c>=d||c>=e||c>=f||d>=e||d>=f||e>=f) continue;
			mx=0;
			cnt=a[b]+a[c]+a[d]+a[e]+a[f];
			mx=max(a[b],a[c]),mx=max(mx,a[d]),mx=max(mx,a[e]);
			mx=max(mx,a[f]);
			if(cnt>mx*2) ans=(((ans+1)%mod)+mod)%mod;
		}
		for(int b=1;b<=n;b++)
		for(int c=2;c<=n;c++)
		for(int d=3;d<=n;d++)
		for(int e=4;e<=n;e++)
		for(int f=5;f<=n;f++)
		for(int g=6;g<=n;g++){
			if(b>=c||b>=d||b>=e||b>=f||b>=g||c>=d||c>=e||c>=f||c>=g||d>=e||d>=f||d>=g||e>=f||e>=g||f>=g) continue;
			mx=0;
			cnt=a[b]+a[c]+a[d]+a[e]+a[f]+a[g];
			mx=max(a[b],a[c]),mx=max(mx,a[d]),mx=max(mx,a[e]);
			mx=max(mx,a[f]),mx=max(mx,a[g]);
			if(cnt>mx*2) ans=(((ans+1)%mod)+mod)%mod;
		}
		for(int b=1;b<=n;b++)
		for(int c=2;c<=n;c++)
		for(int d=3;d<=n;d++)
		for(int e=4;e<=n;e++)
		for(int f=5;f<=n;f++)
		for(int g=6;g<=n;g++)
		for(int h=7;h<=n;h++){
			if(b>=c||b>=d||b>=e||b>=f||b>=g||b>=h||c>=d||c>=e||c>=f||c>=g||c>=h||d>=e||d>=f||d>=g||d>=h||e>=f||e>=g||e>=h||f>=g||f>=h||g>=h) continue;
			mx=0;
			cnt=a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h];
			mx=max(a[b],a[c]),mx=max(mx,a[d]),mx=max(mx,a[e]);
			mx=max(mx,a[f]),mx=max(mx,a[g]),mx=max(mx,a[h]);
			if(cnt>mx*2) ans=(((ans+1)%mod)+mod)%mod;
		}
		cnt=a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8];
		mx=max(a[1],a[2]),mx=max(mx,a[3]),mx=max(mx,a[4]),mx=max(mx,a[5]);
		mx=max(mx,a[6]),mx=max(mx,a[7]),mx=max(mx,a[8]);
		if(cnt>mx*2) ans=(((ans+1)%mod)+mod)%mod;
	}
	if(n==9){
		for(int i=1;i<=n;i++)
		for(int j=2;j<=n;j++)
		for(int k=3;k<=n;k++){
			if(i>=j||j>=k||i>=k) continue;
			mx=0;
			cnt=a[i]+a[j]+a[k],mx=max(a[i],a[j]),mx=max(mx,a[k]);
			if(cnt>mx*2) ans=(((ans+1)%mod)+mod)%mod;
		}
		for(int b=1;b<=n;b++)
		for(int c=2;c<=n;c++)
		for(int d=3;d<=n;d++)
		for(int e=4;e<=n;e++){
			if(b>=c||b>=d||b>=e||c>=d||c>=e||d>=e) continue;
			mx=0;
			cnt=a[b]+a[c]+a[d]+a[e];
			mx=max(a[b],a[c]),mx=max(mx,a[d]),mx=max(mx,a[e]);
			if(cnt>mx*2) ans=(((ans+1)%mod)+mod)%mod;
		}
		for(int b=1;b<=n;b++)
		for(int c=2;c<=n;c++)
		for(int d=3;d<=n;d++)
		for(int e=4;e<=n;e++)
		for(int f=5;f<=n;f++){
			if(b>=c||b>=d||b>=e||b>=f||c>=d||c>=e||c>=f||d>=e||d>=f||e>=f) continue;
			mx=0;
			cnt=a[b]+a[c]+a[d]+a[e]+a[f];
			mx=max(a[b],a[c]),mx=max(mx,a[d]),mx=max(mx,a[e]);
			mx=max(mx,a[f]);
			if(cnt>mx*2) ans=(((ans+1)%mod)+mod)%mod;
		}
		for(int b=1;b<=n;b++)
		for(int c=2;c<=n;c++)
		for(int d=3;d<=n;d++)
		for(int e=4;e<=n;e++)
		for(int f=5;f<=n;f++)
		for(int g=6;g<=n;g++){
			if(b>=c||b>=d||b>=e||b>=f||b>=g||c>=d||c>=e||c>=f||c>=g||d>=e||d>=f||d>=g||e>=f||e>=g||f>=g) continue;
			mx=0;
			cnt=a[b]+a[c]+a[d]+a[e]+a[f]+a[g];
			mx=max(a[b],a[c]),mx=max(mx,a[d]),mx=max(mx,a[e]);
			mx=max(mx,a[f]),mx=max(mx,a[g]);
			if(cnt>mx*2) ans=(((ans+1)%mod)+mod)%mod;
		}
		for(int b=1;b<=n;b++)
		for(int c=2;c<=n;c++)
		for(int d=3;d<=n;d++)
		for(int e=4;e<=n;e++)
		for(int f=5;f<=n;f++)
		for(int g=6;g<=n;g++)
		for(int h=7;h<=n;h++){
			if(b>=c||b>=d||b>=e||b>=f||b>=g||b>=h||c>=d||c>=e||c>=f||c>=g||c>=h||d>=e||d>=f||d>=g||d>=h||e>=f||e>=g||e>=h||f>=g||f>=h||g>=h) continue;
			mx=0;
			cnt=a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h];
			mx=max(a[b],a[c]),mx=max(mx,a[d]),mx=max(mx,a[e]);
			mx=max(mx,a[f]),mx=max(mx,a[g]),mx=max(mx,a[h]);
			if(cnt>mx*2) ans=(((ans+1)%mod)+mod)%mod;
		}
		for(int b=1;b<=n;b++)
		for(int c=2;c<=n;c++)
		for(int d=3;d<=n;d++)
		for(int e=4;e<=n;e++)
		for(int f=5;f<=n;f++)
		for(int g=6;g<=n;g++)
		for(int h=7;h<=n;h++)
		for(int i=8;i<=n;i++){
			if(b>=c||b>=d||b>=e||b>=f||b>=g||b>=h||b>=i||c>=d||c>=e||c>=f||c>=g||c>=h||c>=i||d>=e||d>=f||d>=g||d>=h||d>=i||e>=f||e>=g||e>=h||e>=i||f>=g||f>=h||f>=i||g>=h||g>=i||h>=i) continue;
			mx=0;
			cnt=a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[i];
			mx=max(a[b],a[c]),mx=max(mx,a[d]);
			mx=max(mx,a[e]),mx=max(mx,a[f]);
			mx=max(mx,a[g]),mx=max(mx,a[h]);
			mx=max(mx,a[i]);
			if(cnt>mx*2) ans=(((ans+1)%mod)+mod)%mod;
		}
		cnt=a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9];
		mx=max(a[1],a[2]),mx=max(mx,a[3]),mx=max(mx,a[4]),mx=max(mx,a[5]);
		mx=max(mx,a[6]),mx=max(mx,a[7]),mx=max(mx,a[8]),mx=max(mx,a[9]);
		if(cnt>mx*2) ans=(((ans+1)%mod)+mod)%mod;
	}
	if(n==10){
		for(int i=1;i<=n;i++)
		for(int j=2;j<=n;j++)
		for(int k=3;k<=n;k++){
			if(i>=j||j>=k||i>=k) continue;
			mx=0;
			cnt=a[i]+a[j]+a[k],mx=max(a[i],a[j]),mx=max(mx,a[k]);
			if(cnt>mx*2) ans=(((ans+1)%mod)+mod)%mod;
		}
		for(int b=1;b<=n;b++)
		for(int c=2;c<=n;c++)
		for(int d=3;d<=n;d++)
		for(int e=4;e<=n;e++){
			if(b>=c||b>=d||b>=e||c>=d||c>=e||d>=e) continue;
			mx=0;
			cnt=a[b]+a[c]+a[d]+a[e];
			mx=max(a[b],a[c]),mx=max(mx,a[d]),mx=max(mx,a[e]);
			if(cnt>mx*2) ans=(((ans+1)%mod)+mod)%mod;
		}
		for(int b=1;b<=n;b++)
		for(int c=2;c<=n;c++)
		for(int d=3;d<=n;d++)
		for(int e=4;e<=n;e++)
		for(int f=5;f<=n;f++){
			if(b>=c||b>=d||b>=e||b>=f||c>=d||c>=e||c>=f||d>=e||d>=f||e>=f) continue;
			mx=0;
			cnt=a[b]+a[c]+a[d]+a[e]+a[f];
			mx=max(a[b],a[c]),mx=max(mx,a[d]),mx=max(mx,a[e]);
			mx=max(mx,a[f]);
			if(cnt>mx*2) ans=(((ans+1)%mod)+mod)%mod;
		}
		for(int b=1;b<=n;b++)
		for(int c=2;c<=n;c++)
		for(int d=3;d<=n;d++)
		for(int e=4;e<=n;e++)
		for(int f=5;f<=n;f++)
		for(int g=6;g<=n;g++){
			if(b>=c||b>=d||b>=e||b>=f||b>=g||c>=d||c>=e||c>=f||c>=g||d>=e||d>=f||d>=g||e>=f||e>=g||f>=g) continue;
			mx=0;
			cnt=a[b]+a[c]+a[d]+a[e]+a[f]+a[g];
			mx=max(a[b],a[c]),mx=max(mx,a[d]),mx=max(mx,a[e]);
			mx=max(mx,a[f]),mx=max(mx,a[g]);
			if(cnt>mx*2) ans=(((ans+1)%mod)+mod)%mod;
		}
		for(int b=1;b<=n;b++)
		for(int c=2;c<=n;c++)
		for(int d=3;d<=n;d++)
		for(int e=4;e<=n;e++)
		for(int f=5;f<=n;f++)
		for(int g=6;g<=n;g++)
		for(int h=7;h<=n;h++){
			if(b>=c||b>=d||b>=e||b>=f||b>=g||b>=h||c>=d||c>=e||c>=f||c>=g||c>=h||d>=e||d>=f||d>=g||d>=h||e>=f||e>=g||e>=h||f>=g||f>=h||g>=h) continue;
			mx=0;
			cnt=a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h];
			mx=max(a[b],a[c]),mx=max(mx,a[d]),mx=max(mx,a[e]);
			mx=max(mx,a[f]),mx=max(mx,a[g]),mx=max(mx,a[h]);
			if(cnt>mx*2) ans=(((ans+1)%mod)+mod)%mod;
		}
		for(int b=1;b<=n;b++)
		for(int c=2;c<=n;c++)
		for(int d=3;d<=n;d++)
		for(int e=4;e<=n;e++)
		for(int f=5;f<=n;f++)
		for(int g=6;g<=n;g++)
		for(int h=7;h<=n;h++)
		for(int i=8;i<=n;i++){
			if(b>=c||b>=d||b>=e||b>=f||b>=g||b>=h||b>=i||c>=d||c>=e||c>=f||c>=g||c>=h||c>=i||d>=e||d>=f||d>=g||d>=h||d>=i||e>=f||e>=g||e>=h||e>=i||f>=g||f>=h||f>=i||g>=h||g>=i||h>=i) continue;
			mx=0;
			cnt=a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[i];
			mx=max(a[b],a[c]),mx=max(mx,a[d]);
			mx=max(mx,a[e]),mx=max(mx,a[f]);
			mx=max(mx,a[g]),mx=max(mx,a[h]);
			mx=max(mx,a[i]);
			if(cnt>mx*2) ans=(((ans+1)%mod)+mod)%mod;
		}
		for(int b=1;b<=n;b++)
		for(int c=2;c<=n;c++)
		for(int d=3;d<=n;d++)
		for(int e=4;e<=n;e++)
		for(int f=5;f<=n;f++)
		for(int g=6;g<=n;g++)
		for(int h=7;h<=n;h++)
		for(int i=8;i<=n;i++)
		for(int j=1;j<=9;j++){
			if(b>=c||b>=d||b>=e||b>=f||b>=g||b>=h||b>=i||b>=j||c>=d||c>=e||c>=f||c>=g||c>=h||c>=i||c>=j||d>=e||d>=f||d>=g||d>=h||d>=i||d>=j||e>=f||e>=g||e>=h||e>=i||e>=j||f>=g||f>=h||f>=i||f>=j||g>=h||g>=i||g>=j||h>=i||h>=j||i>=j) continue;
			mx=0;
			cnt=a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[i]+a[j];
			mx=max(a[b],a[c]),mx=max(mx,a[d]);
			mx=max(mx,a[e]),mx=max(mx,a[f]);
			mx=max(mx,a[g]),mx=max(mx,a[h]);
			mx=max(mx,a[i]),mx=max(mx,a[j]);
			if(cnt>mx*2) ans=(((ans+1)%mod)+mod)%mod;
		}
		cnt=a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10];
		mx=max(a[1],a[2]),mx=max(mx,a[3]),mx=max(mx,a[4]),mx=max(mx,a[5]);
		mx=max(mx,a[6]),mx=max(mx,a[7]),mx=max(mx,a[8]),mx=max(mx,a[9]);
		mx=max(mx,a[10]);
		if(cnt>mx*2) ans=(((ans+1)%mod)+mod)%mod;
		cout<<ans<<"\n";
	}
	cout<<ans<<"\n";
	return 0;
}

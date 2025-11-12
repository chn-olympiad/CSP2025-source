#include <bits/stdc++.h>
using namespace std;
int t,a[10010],b[10010],c[10010],s[10010],cnt[10010];
int q[10010],w[10010],u[10010];//tongjirenshu.
void ddd(int k) {
//	if(a[k]>b[k]&&a[k]>c[k]&&u[k]!=a[k]/2) {
//		q[k]+=1;//amax
//	} 
    if(a[k]<b[k]&&a[k]<c[k]) {
		if(b[k]>c[k]&&w[k]!=s[k]/2) {
			w[k]+=1;//amin
		}
		else if(b[k]<c[k]&&u[k]!=s[k]/2) u[k]+=1;
		else q[k]++;
} 
 else if(b[k]<a[k]&&b[k]<c[k]) {
		if(a[k]>c[k]&&q[k]!=s[k]/2) {
			q[k]+=1;//bmin
		}
		else if(a[k]<c[k]&&u[k]!=s[k]/2) u[k]+=1;
		else w[k]++;
	}
		 else if(c[k]<b[k]&&c[k]<a[k]) {
		if(b[k]>a[k]&&w[k]!=s[k]/2) {
			w[k]+=1;//cmin
		}
		else if(b[k]<a[k]&&q[k]!=s[k]/2) q[k]+=1;
		else u[k]++;
	}
//else if(b[k]>c[k]&&a[k]>c[k]) {
//		if(b[k]>a[k]&&w[k]!=a[k]/2) {
//			w[k]++;
//		} else if(b[k]<a[k]&&w[k]!=a[k]/2) {
//			q[k]++;
//		} else u[k]++;
//	} else if(c[k]<b[k]&&a[k]<c[k]) {
//		u[k]+=1;//cmid;
//	} else if(c[k]>b[k]&&a[k]<c[k]) {
//		u[k]+=1;//cmid;
//	}
	for(int i=1; i<=t; i++) {
		for(int j=1; j<=s[k]; j++) {
			if(q[j]==1) {
				cnt[i]+=a[j];
			} else if(w[j]==1) {
				cnt[i]+=b[j];
			} else if(u[j]==1) {
				cnt[i]+=c[j];
			}
		}
	}
	k++;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1; i<=t; i++) {
		cin>>s[i];
		for(int j=1; j<=s[i]; j++) {
			cin>>a[j]>>b[j]>>c[j];
		}
	}
	for(int i=1; i<=t; i++) {
		for(int j=1; j<=s[i]; j++) {
			ddd(i);
			
		}
	}
	for(int i=1; i<=t; i++) {
		cout<<cnt[i]<<endl;
	}

	return 0;
}

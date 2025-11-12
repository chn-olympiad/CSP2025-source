#include<bits/stdc++.h>
using namespace std;
int n,a[100005],ans[100005][100005],s=1,sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin >> n ;
    for(int i=1;i<=n;i++)cin >> a[i] ;
    sort(a+1,a+n+1);
    if(n==3){
    	if(a[3]<a[1]+a[2])cout << 1 ;
        else cout << 0 ;
        return 0;
    }     
//	}else{
//		for(int i=1;i<=n;i++){
//    	    for(int j=s;j<=n;j++){
//    	    	ans[j][s]=a[j]+a[j+1];
//    	    	a[j+1]=a[j]+a[j+1];
//	    	}
//		    s++;
//	    }
//    	s--;
//	    for(int i=3;i<=s;i++){
//	    	for(int j=i;j<=s;j++){
//			    if(ans[j][i]>a[i]){
//			    	sum++;
//				}
//	    	}
//    	}
//	    cout << sum ;
//	}
//    
	return 0;
}


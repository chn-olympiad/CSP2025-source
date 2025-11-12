#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],b[100005],k,ans,t;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>1) t=0;
	}
	sort(a+1,a+n+1);
	if(n<3 || t==1) cout<<0;
	else if(n==3)
	{
		for(int i=1;i<=n;i++)
		   ans+=a[i];
		if(ans>a[3]*2) cout<<1;
		else cout<<0;
	}
	
	
	else 
	{
		for(int i=1;i<=n;i++)
	   for(int i1=i+1;i1<=n;i1++)
	   	    for(int i2=i1+1;i2<=n;i2++)
	   	        if(a[i]+a[i1]+a[i2]>a[i2]*2) ans++,ans%=998244353;
	   for(int i=1;i<=n;i++)
	   for(int i1=i+1;i1<=n;i1++)
	   	    for(int i2=i1+1;i2<=n;i2++)
	   	    	for(int i3=i2+1;i3<=n;i3++)
		        	    if(a[i1]+a[i2]+a[i3]+a[i]>a[i3]*2) ans++,ans%=998244353;
	   for(int i=1;i<=n;i++)
	      for(int i1=i+1;i1<=n;i1++)
	   	    for(int i2=i1+1;i2<=n;i2++)
	   	    	for(int i3=i2+1;i3<=n;i3++)
	   	    	    for(int i4=i3+1;i4<=n;i4++)
		        	    if(a[i1]+a[i2]+a[i3]+a[i]+a[i4]>a[i4]*2) ans++,ans%=998244353;
		for(int i=1;i<=n;i++)
	      for(int i1=i+1;i1<=n;i1++)
	   	    for(int i2=i1+1;i2<=n;i2++)
	   	    	for(int i3=i2+1;i3<=n;i3++)
	   	    	    for(int i4=i3+1;i4<=n;i4++)
	   	    	    for(int i5=i4+1;i5<=n;i5++)
		        	    if(a[i1]+a[i2]+a[i3]+a[i]+a[i4]+a[i5]>a[i5]*2) ans++,ans%=998244353; 
		for(int i=1;i<=n;i++)
	      for(int i1=i+1;i1<=n;i1++)
	   	    for(int i2=i1+1;i2<=n;i2++)
	   	    	for(int i3=i2+1;i3<=n;i3++)
	   	    	    for(int i4=i3+1;i4<=n;i4++)
	   	    	        for(int i5=i4+1;i5<=n;i5++)
	   	    	            for(int i6=i5+1;i6<=n;i6++)
		        	    if(a[i1]+a[i2]+a[i3]+a[i]+a[i4]+a[i5]+a[i6]>a[i6]*2) ans++,ans%=998244353;
		for(int i=1;i<=n;i++)
	      for(int i1=i+1;i1<=n;i1++)
	   	    for(int i2=i1+1;i2<=n;i2++)
	   	    	for(int i3=i2+1;i3<=n;i3++)
	   	    	    for(int i4=i3+1;i4<=n;i4++)
	   	    	        for(int i5=i4+1;i5<=n;i5++)
	   	    	            for(int i6=i5+1;i6<=n;i6++)
	   	    	            for(int i7=i6+1;i7<=n;i7++)
		        	    if(a[i1]+a[i2]+a[i3]+a[i]+a[i4]+a[i5]+a[i6]+a[i7]>a[i7]*2) ans++,ans%=998244353;
		for(int i=1;i<=n;i++)
	      for(int i1=i+1;i1<=n;i1++)
	   	    for(int i2=i1+1;i2<=n;i2++)
	   	    	for(int i3=i2+1;i3<=n;i3++)
	   	    	    for(int i4=i3+1;i4<=n;i4++)
	   	    	        for(int i5=i4+1;i5<=n;i5++)
	   	    	            for(int i6=i5+1;i6<=n;i6++)
	   	    	            for(int i7=i6+1;i7<=n;i7++)
	   	    	            for(int i8=i7+1;i8<=n;i8++)
		        	    if(a[i1]+a[i2]+a[i3]+a[i]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]>a[i8]*2) ans++,ans%=998244353;

	    for(int i=1;i<=n;i++)
	      for(int i1=i+1;i1<=n;i1++)
	   	    for(int i2=i1+1;i2<=n;i2++)
	   	    	for(int i3=i2+1;i3<=n;i3++)
	   	    	    for(int i4=i3+1;i4<=n;i4++)
	   	    	        for(int i5=i4+1;i5<=n;i5++)
	   	    	            for(int i6=i5+1;i6<=n;i6++)
	   	    	            for(int i7=i6+1;i7<=n;i7++)
	   	    	             for(int i8=i7+1;i8<=n;i8++)
	   	    	              for(int i9=i8+1;i9<=n;i9++)
		        	    if(a[i1]+a[i2]+a[i3]+a[i]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]>a[i9]*2) ans++,ans%=998244353;
						for(int i=1;i<=n;i++)
	      for(int i1=i+1;i1<=n;i1++)
	   	    for(int i2=i1+1;i2<=n;i2++)
	   	    	for(int i3=i2+1;i3<=n;i3++)
	   	    	    for(int i4=i3+1;i4<=n;i4++)
	   	    	        for(int i5=i4+1;i5<=n;i5++)
	   	    	            for(int i6=i5+1;i6<=n;i6++)
	   	    	            for(int i7=i6+1;i7<=n;i7++)
		        	    for(int i8=i7+1;i8<=n;i8++)
	   	    	              for(int i9=i8+1;i9<=n;i9++)
	   	    	              for(int i10=i9+1;i10<=n;i10++)
		        	    if(a[i1]+a[i2]+a[i3]+a[i]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]>a[i10]*2) ans++,ans%=998244353;
			for(int i=1;i<=n;i++)
	      for(int i1=i+1;i1<=n;i1++)
	   	    for(int i2=i1+1;i2<=n;i2++)
	   	    	for(int i3=i2+1;i3<=n;i3++)
	   	    	    for(int i4=i3+1;i4<=n;i4++)
	   	    	        for(int i5=i4+1;i5<=n;i5++)
	   	    	            for(int i6=i5+1;i6<=n;i6++)
	   	    	            for(int i7=i6+1;i7<=n;i7++)
		        	    for(int i8=i7+1;i8<=n;i8++)
	   	    	              for(int i9=i8+1;i9<=n;i9++)
	   	    	              for(int i10=i9+1;i10<=n;i10++)
	   	    	               for(int i11=i10+1;i11<=n;i11++)
		        	    if(a[i1]+a[i2]+a[i3]+a[i]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]+a[i11]>a[i11]*2) ans++,ans%=998244353;
     	  for(int i=1;i<=n;i++)
	      for(int i1=i+1;i1<=n;i1++)
	   	    for(int i2=i1+1;i2<=n;i2++)
	   	    	for(int i3=i2+1;i3<=n;i3++)
	   	    	    for(int i4=i3+1;i4<=n;i4++)
	   	    	        for(int i5=i4+1;i5<=n;i5++)
	   	    	            for(int i6=i5+1;i6<=n;i6++)
	   	    	            for(int i7=i6+1;i7<=n;i7++)
		        	    for(int i8=i7+1;i8<=n;i8++)
	   	    	              for(int i9=i8+1;i9<=n;i9++)
	   	    	              for(int i10=i9+1;i10<=n;i10++)
	   	    	               for(int i11=i10+1;i11<=n;i11++)
	   	    	               for(int i12=i11+1;i12<=n;i12++)
		        	    if(a[i1]+a[i2]+a[i3]+a[i]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]+a[i11]+a[i12]>a[i12]*2) ans++,ans%=998244353;
		
			cout<<ans;					
		}
	
	return 0;
} 

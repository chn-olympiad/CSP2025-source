#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
long long n,a[50005],q[50005],t;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i],q[i]=q[i-1]+a[i];
	sort(a+1,a+1+n);
	if(a[n]==1)
	{
		long long s=1;
		for(int i=1;i<=n;i++)
		s=s*2%M;
		s=(s+M-1-n-n*(n-1)/2)%M;
		cout<<s;
		return 0;
	}
	if(n>=3)
	{
		if(q[3]>2*a[3])t++;
		t%=M;
		//cout<<t<<endl;
	}
	if(n>=4)
	{
	//	if(q[3]>2*a[3])t++;
		if(q[4]>2*a[4])t++;
		if(q[4]-a[1]>2*a[4])t++;
		if(q[4]-a[2]>2*a[4])t++;
		if(q[4]-a[3]>2*a[4])t++;
		t%=M;
	//	cout<<t<<endl;
	}
	if(n>=5)
	{
		if(q[5]>2*a[5])t++;
		//cout<<t<<endl;
		for(int i=1;i<=4;i++)
		if(q[5]-a[i]>2*a[5])t++;
		//cout<<t<<endl;
		for(int i=1;i<=3;i++)
			for(int j=i+1;j<=4;j++)
				if(q[5]-a[i]-a[j]>2*a[5])t++;
		t%=M;
		//cout<<t<<endl;
	}
	if(n>=6)
	{
		if(q[6]>2*a[6])t++;
		//cout<<t<<endl;
		for(int i=1;i<=5;i++)
		if(q[6]-a[i]>2*a[6])t++;
		//cout<<t<<endl;
		for(int i=1;i<=4;i++)
			for(int j=i+1;j<=5;j++)
				if(q[6]-a[i]-a[j]>2*a[6])t++;
		for(int i=1;i<=3;i++)
			for(int j=i+1;j<=4;j++)
				for(int k=j+1;k<=5;k++)
				if(q[6]-a[i]-a[j]-a[k]>2*a[6])t++;
		t%=M;
		//cout<<t<<endl;
	}
	if(n>=7)
	{
		if(q[7]>2*a[7])t++;
		//cout<<t<<endl;
		for(int i=1;i<=6;i++)
		if(q[7]-a[i]>2*a[7])t++;
		//cout<<t<<endl;
		for(int i=1;i<=5;i++)
			for(int j=i+1;j<=6;j++)
				if(q[7]-a[i]-a[j]>2*a[7])t++;
		for(int i=1;i<=4;i++)
			for(int j=i+1;j<=5;j++)
				for(int k=j+1;k<=6;k++)
				if(q[7]-a[i]-a[j]-a[k]>2*a[7])t++;
		for(int i=1;i<=3;i++)
			for(int j=i+1;j<=4;j++)
				for(int k=j+1;k<=5;k++)
					for(int x=k+1;x<=6;x++)
					if(q[7]-a[i]-a[j]-a[k]-a[x]>2*a[7])t++;
		t%=M;
		//cout<<t<<endl;
	}
	if(n>=8)
	{
		if(q[8]>2*a[8])t++;
		//cout<<t<<endl;
		for(int i=1;i<=7;i++)
		if(q[8]-a[i]>2*a[8])t++;
		//cout<<t<<endl;
		for(int i=1;i<=6;i++)
			for(int j=i+1;j<=7;j++)
				if(q[8]-a[i]-a[j]>2*a[8])t++;
		for(int i=1;i<=5;i++)
			for(int j=i+1;j<=6;j++)
				for(int k=j+1;k<=7;k++)
				if(q[8]-a[i]-a[j]-a[k]>2*a[8])t++;
		for(int i=1;i<=4;i++)
			for(int j=i+1;j<=5;j++)
				for(int k=j+1;k<=6;k++)
					for(int x=k+1;x<=7;x++)
					if(q[8]-a[i]-a[j]-a[k]-a[x]>2*a[8])t++;
		for(int i=1;i<=3;i++)
			for(int j=i+1;j<=4;j++)
				for(int k=j+1;k<=5;k++)
					for(int x=k+1;x<=6;x++)
						for(int y=x+1;y<=7;y++)
						if(q[8]-a[i]-a[j]-a[k]-a[x]-a[y]>2*a[8])t++;
		t%=M;
		//cout<<t<<endl;
	}
	if(n>=9)
	{
		if(q[9]>2*a[9])t++;
		//cout<<t<<endl;
		for(int i=1;i<=8;i++)
		if(q[9]-a[i]>2*a[9])t++;
		//cout<<t<<endl;
		for(int i=1;i<=7;i++)
			for(int j=i+1;j<=8;j++)
				if(q[9]-a[i]-a[j]>2*a[9])t++;
		for(int i=1;i<=6;i++)
			for(int j=i+1;j<=7;j++)
				for(int k=j+1;k<=8;k++)
				if(q[9]-a[i]-a[j]-a[k]>2*a[9])t++;
		for(int i=1;i<=5;i++)
			for(int j=i+1;j<=6;j++)
				for(int k=j+1;k<=7;k++)
					for(int x=k+1;x<=8;x++)
					if(q[9]-a[i]-a[j]-a[k]-a[x]>2*a[9])t++;
		for(int i=1;i<=4;i++)
			for(int j=i+1;j<=5;j++)
				for(int k=j+1;k<=6;k++)
					for(int x=k+1;x<=7;x++)
						for(int y=x+1;y<=8;y++)
						if(q[9]-a[i]-a[j]-a[k]-a[x]-a[y]>2*a[9])t++;
		for(int i=1;i<=3;i++)
			for(int j=i+1;j<=4;j++)
				for(int k=j+1;k<=5;k++)
					for(int x=k+1;x<=6;x++)
						for(int y=x+1;y<=7;y++)
							for(int z=y+1;z<=8;z++)
							if(q[9]-a[i]-a[j]-a[k]-a[x]-a[y]-a[z]>2*a[9])t++;
		t%=M;
		//cout<<t<<endl;
	}
	if(n>=10)
	{
		if(q[10]>2*a[10])t++;
		//cout<<t<<endl;
		for(int i=1;i<=9;i++)
		if(q[10]-a[i]>2*a[10])t++;
		//cout<<t<<endl;
		for(int i=1;i<=8;i++)
			for(int j=i+1;j<=9;j++)
				if(q[10]-a[i]-a[j]>2*a[10])t++;
		for(int i=1;i<=7;i++)
			for(int j=i+1;j<=8;j++)
				for(int k=j+1;k<=9;k++)
				if(q[10]-a[i]-a[j]-a[k]>2*a[10])t++;
		for(int i=1;i<=6;i++)
			for(int j=i+1;j<=7;j++)
				for(int k=j+1;k<=8;k++)
					for(int x=k+1;x<=9;x++)
					if(q[10]-a[i]-a[j]-a[k]-a[x]>2*a[10])t++;
		for(int i=1;i<=5;i++)
			for(int j=i+1;j<=6;j++)
				for(int k=j+1;k<=7;k++)
					for(int x=k+1;x<=8;x++)
						for(int y=x+1;y<=9;y++)
						if(q[10]-a[i]-a[j]-a[k]-a[x]-a[y]>2*a[10])t++;
		for(int i=1;i<=4;i++)
			for(int j=i+1;j<=5;j++)
				for(int k=j+1;k<=6;k++)
					for(int x=k+1;x<=7;x++)
						for(int y=x+1;y<=8;y++)
							for(int z=y+1;z<=9;z++)
							if(q[10]-a[i]-a[j]-a[k]-a[x]-a[y]-a[z]>2*a[10])t++;
		for(int i=1;i<=3;i++)
			for(int j=i+1;j<=4;j++)
				for(int k=j+1;k<=5;k++)
					for(int x=k+1;x<=6;x++)
						for(int y=x+1;y<=7;y++)
							for(int z=y+1;z<=8;z++)
								for(int s=z+1;s<=9;s++)
								if(q[10]-a[i]-a[j]-a[k]-a[x]-a[y]-a[z]-a[s]>2*a[10])t++;
		t%=M;
		//cout<<t<<endl;
	}
	cout<<t;
	return 0;
}

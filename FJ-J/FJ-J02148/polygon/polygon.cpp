#include<bits/stdc++.h>
using namespace std;
int n,u,a[5005];
long long s,w[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			u=1;
		}
	}
	sort(a+1,a+n+1);
	if(n<3)
	{
		cout<<"0";
		return 0;
	}
	if(n==3)
	{
		if(2*a[3]<a[1]+a[2]+a[3])
		{
			cout<<"1";
			return 0;
		}
		else
		{
			cout<<"0";
			return 0;
		}
	}
	else if(n<=20&&n>3&&u==1)
	{
		for(int i=1;i<=n-2;i++)
			for(int j=i+1;j<=n-1;j++)
				for(int k=j+1;k<=n;k++)
				    if(a[i]+a[j]+a[k]>2*a[k])
						s+=1;
		for(int i=1;i<=n-3;i++)
			for(int j=i+1;j<=n-2;j++)
				for(int k=j+1;k<=n-1;k++)
					for(int t=k+1;t<=n;t++)
						if(a[i]+a[j]+a[k]+a[t]>2*a[t])
							s+=1;
		for(int i=1;i<=n-4;i++)
			for(int j=i+1;j<=n-3;j++)
				for(int k=j+1;k<=n-2;k++)
					for(int t=k+1;t<=n-1;t++)
					    for(int x=t+1;x<=n;x++)
						    if(a[i]+a[j]+a[k]+a[t]+a[x]>2*a[x])
							    s+=1;
		for(int i=1;i<=n-5;i++)
			for(int j=i+1;j<=n-4;j++)
				for(int k=j+1;k<=n-3;k++)
					for(int t=k+1;t<=n-2;t++)
					    for(int x=t+1;x<=n-1;x++)
					        for(int y=x+1;y<=n;y++)
						        if(a[i]+a[j]+a[k]+a[t]+a[x]+a[y]>2*a[y])
							        s+=1;
		for(int i=1;i<=n-6;i++)
			for(int j=i+1;j<=n-5;j++)
				for(int k=j+1;k<=n-4;k++)
					for(int t=k+1;t<=n-3;t++)
					    for(int x=t+1;x<=n-2;x++)
					        for(int y=x+1;y<=n-1;y++)
					            for(int z=y+1;z<=n;z++)
						            if(a[i]+a[j]+a[k]+a[t]+a[x]+a[y]+a[z]>2*a[z])
							            s+=1;
		for(int i=1;i<=n-7;i++)
			for(int j=i+1;j<=n-6;j++)
				for(int k=j+1;k<=n-5;k++)
					for(int t=k+1;t<=n-4;t++)
					    for(int x=t+1;x<=n-3;x++)
					        for(int y=x+1;y<=n-2;y++)
					            for(int z=y+1;z<=n-1;z++)
					                for(int b=z+1;b<=n;b++)
						            if(a[i]+a[j]+a[k]+a[t]+a[x]+a[y]+a[z]+a[b]>2*a[b])
							            s+=1;
		for(int i=1;i<=n-8;i++)
			for(int j=i+1;j<=n-7;j++)
				for(int k=j+1;k<=n-6;k++)
					for(int t=k+1;t<=n-5;t++)
					    for(int x=t+1;x<=n-4;x++)
					        for(int y=x+1;y<=n-3;y++)
					            for(int z=y+1;z<=n-2;z++)
					                for(int b=z+1;b<=n-1;b++)
					                    for(int c=b+1;c<=n;c++)
						                    if(a[i]+a[j]+a[k]+a[t]+a[x]+a[y]+a[z]+a[b]+a[c]>2*a[c])
							                    s+=1;		
		for(int i=1;i<=n-9;i++)
			for(int j=i+1;j<=n-8;j++)
				for(int k=j+1;k<=n-7;k++)
					for(int t=k+1;t<=n-6;t++)
					    for(int x=t+1;x<=n-5;x++)
					        for(int y=x+1;y<=n-4;y++)
					            for(int z=y+1;z<=n-3;z++)
					                for(int b=z+1;b<=n-2;b++)
					                    for(int c=b+1;c<=n-1;c++)
					                        for(int d=c+1;d<=n;d++)
						                        if(a[i]+a[j]+a[k]+a[t]+a[x]+a[y]+a[z]+a[b]+a[c]+a[d]>2*a[d])
							                        s+=1;												
		for(int i=1;i<=n-10;i++)
			for(int j=i+1;j<=n-9;j++)
				for(int k=j+1;k<=n-8;k++)
					for(int t=k+1;t<=n-7;t++)
					    for(int x=t+1;x<=n-6;x++)
					        for(int y=x+1;y<=n-5;y++)
					            for(int z=y+1;z<=n-4;z++)
					                for(int b=z+1;b<=n-3;b++)
					                    for(int c=b+1;c<=n-2;c++)
					                        for(int d=c+1;d<=n-1;d++)
					                            for(int e=d+1;e<=n;e++)
						                            if(a[i]+a[j]+a[k]+a[t]+a[x]+a[y]+a[z]+a[b]+a[c]+a[d]+a[e]>2*a[e])
							                            s+=1;
		for(int i=1;i<=n-11;i++)
			for(int j=i+1;j<=n-10;j++)
				for(int k=j+1;k<=n-9;k++)
					for(int t=k+1;t<=n-8;t++)
					    for(int x=t+1;x<=n-7;x++)
					        for(int y=x+1;y<=n-6;y++)
					            for(int z=y+1;z<=n-5;z++)
					                for(int b=z+1;b<=n-4;b++)
					                    for(int c=b+1;c<=n-3;c++)
					                        for(int d=c+1;d<=n-2;d++)
					                            for(int e=d+1;e<=n-1;e++)
					                                for(int f=e+1;f<=n;f++)
						                                if(a[i]+a[j]+a[k]+a[t]+a[x]+a[y]+a[z]+a[b]+a[c]+a[d]+a[e]+a[f]>2*a[f])
							                                s+=1;	
		for(int i=1;i<=n-12;i++)
			for(int j=i+1;j<=n-11;j++)
				for(int k=j+1;k<=n-10;k++)
					for(int t=k+1;t<=n-9;t++)
					    for(int x=t+1;x<=n-8;x++)
					        for(int y=x+1;y<=n-7;y++)
					            for(int z=y+1;z<=n-6;z++)
					                for(int b=z+1;b<=n-5;b++)
					                    for(int c=b+1;c<=n-4;c++)
					                        for(int d=c+1;d<=n-3;d++)
					                            for(int e=d+1;e<=n-2;e++)
					                                for(int f=e+1;f<=n-1;f++)
					                                    for(int g=f+1;g<=n;g++)
						                                    if(a[i]+a[j]+a[k]+a[t]+a[x]+a[y]+a[z]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]>2*a[g])
							                                    s+=1;
		for(int i=1;i<=n-13;i++)
			for(int j=i+1;j<=n-12;j++)
				for(int k=j+1;k<=n-11;k++)
					for(int t=k+1;t<=n-10;t++)
					    for(int x=t+1;x<=n-9;x++)
					        for(int y=x+1;y<=n-8;y++)
					            for(int z=y+1;z<=n-7;z++)
					                for(int b=z+1;b<=n-6;b++)
					                    for(int c=b+1;c<=n-5;c++)
					                        for(int d=c+1;d<=n-4;d++)
					                            for(int e=d+1;e<=n-3;e++)
					                                for(int f=e+1;f<=n-2;f++)
					                                    for(int g=f+1;g<=n-1;g++)
					                                        for(int h=g+1;h<=n;h++)
						                                        if(a[i]+a[j]+a[k]+a[t]+a[x]+a[y]+a[z]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]>2*a[h])
							                                        s+=1;	
		for(int i=1;i<=n-14;i++)
			for(int j=i+1;j<=n-13;j++)
				for(int k=j+1;k<=n-12;k++)
					for(int t=k+1;t<=n-11;t++)
					    for(int x=t+1;x<=n-10;x++)
					        for(int y=x+1;y<=n-9;y++)
					            for(int z=y+1;z<=n-8;z++)
					                for(int b=z+1;b<=n-7;b++)
					                    for(int c=b+1;c<=n-6;c++)
					                        for(int d=c+1;d<=n-5;d++)
					                            for(int e=d+1;e<=n-4;e++)
					                                for(int f=e+1;f<=n-3;f++)
					                                    for(int g=f+1;g<=n-2;g++)
					                                        for(int h=g+1;h<=n-1;h++)
					                                            for(int l=h+1;l<=n;l++)
						                                            if(a[i]+a[j]+a[k]+a[t]+a[x]+a[y]+a[z]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[l]>2*a[l])
							                                            s+=1;
		for(int i=1;i<=n-15;i++)
			for(int j=i+1;j<=n-14;j++)
				for(int k=j+1;k<=n-13;k++)
					for(int t=k+1;t<=n-12;t++)
					    for(int x=t+1;x<=n-11;x++)
					        for(int y=x+1;y<=n-10;y++)
					            for(int z=y+1;z<=n-9;z++)
					                for(int b=z+1;b<=n-8;b++)
					                    for(int c=b+1;c<=n-7;c++)
					                        for(int d=c+1;d<=n-6;d++)
					                            for(int e=d+1;e<=n-5;e++)
					                                for(int f=e+1;f<=n-4;f++)
					                                    for(int g=f+1;g<=n-3;g++)
					                                        for(int h=g+1;h<=n-2;h++)
					                                            for(int l=h+1;l<=n-1;l++)
					                                                for(int m=l+1;m<=n;m++)
						                                                if(a[i]+a[j]+a[k]+a[t]+a[x]+a[y]+a[z]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[l]+a[m]>2*a[m])
							                                                s+=1;	
		for(int i=1;i<=n-16;i++)
			for(int j=i+1;j<=n-15;j++)
				for(int k=j+1;k<=n-14;k++)
					for(int t=k+1;t<=n-13;t++)
					    for(int x=t+1;x<=n-12;x++)
					        for(int y=x+1;y<=n-11;y++)
					            for(int z=y+1;z<=n-10;z++)
					                for(int b=z+1;b<=n-9;b++)
					                    for(int c=b+1;c<=n-8;c++)
					                        for(int d=c+1;d<=n-7;d++)
					                            for(int e=d+1;e<=n-6;e++)
					                                for(int f=e+1;f<=n-5;f++)
					                                    for(int g=f+1;g<=n-4;g++)
					                                        for(int h=g+1;h<=n-3;h++)
					                                            for(int l=h+1;l<=n-2;l++)
					                                                for(int m=l+1;m<=n-1;m++)
					                                                    for(int o=m+1;o<=n;o++)
						                                                    if(a[i]+a[j]+a[k]+a[t]+a[x]+a[y]+a[z]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[l]+a[m]+a[o]>2*a[o])
							                                                    s+=1;
		for(int i=1;i<=n-17;i++)
			for(int j=i+1;j<=n-16;j++)
				for(int k=j+1;k<=n-15;k++)
					for(int t=k+1;t<=n-14;t++)
					    for(int x=t+1;x<=n-13;x++)
					        for(int y=x+1;y<=n-12;y++)
					            for(int z=y+1;z<=n-11;z++)
					                for(int b=z+1;b<=n-10;b++)
					                    for(int c=b+1;c<=n-9;c++)
					                        for(int d=c+1;d<=n-8;d++)
					                            for(int e=d+1;e<=n-7;e++)
					                                for(int f=e+1;f<=n-6;f++)
					                                    for(int g=f+1;g<=n-5;g++)
					                                        for(int h=g+1;h<=n-4;h++)
					                                            for(int l=h+1;l<=n-3;l++)
					                                                for(int m=l+1;m<=n-2;m++)
					                                                    for(int o=m+1;o<=n-1;o++)
					                                                        for(int p=o+1;p<=n;p++)
						                                                        if(a[i]+a[j]+a[k]+a[t]+a[x]+a[y]+a[z]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[l]+a[m]+a[o]+a[p]>2*a[p])
							                                                        s+=1;	
		for(int i=1;i<=n-18;i++)
			for(int j=i+1;j<=n-17;j++)
				for(int k=j+1;k<=n-16;k++)
					for(int t=k+1;t<=n-15;t++)
					    for(int x=t+1;x<=n-14;x++)
					        for(int y=x+1;y<=n-13;y++)
					            for(int z=y+1;z<=n-12;z++)
					                for(int b=z+1;b<=n-11;b++)
					                    for(int c=b+1;c<=n-10;c++)
					                        for(int d=c+1;d<=n-9;d++)
					                            for(int e=d+1;e<=n-8;e++)
					                                for(int f=e+1;f<=n-7;f++)
					                                    for(int g=f+1;g<=n-6;g++)
					                                        for(int h=g+1;h<=n-5;h++)
					                                            for(int l=h+1;l<=n-4;l++)
					                                                for(int m=l+1;m<=n-3;m++)
					                                                    for(int o=m+1;o<=n-2;o++)
					                                                        for(int p=o+1;p<=n-1;p++)
					                                                            for(int q=p+1;q<=n;q++)
						                                                            if(a[i]+a[j]+a[k]+a[t]+a[x]+a[y]+a[z]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[l]+a[m]+a[o]+a[p]+a[q]>2*a[q])
							                                                            s+=1;	
		for(int i=1;i<=n-19;i++)
			for(int j=i+1;j<=n-18;j++)
				for(int k=j+1;k<=n-17;k++)
					for(int t=k+1;t<=n-16;t++)
					    for(int x=t+1;x<=n-15;x++)
					        for(int y=x+1;y<=n-14;y++)
					            for(int z=y+1;z<=n-13;z++)
					                for(int b=z+1;b<=n-12;b++)
					                    for(int c=b+1;c<=n-11;c++)
					                        for(int d=c+1;d<=n-10;d++)
					                            for(int e=d+1;e<=n-9;e++)
					                                for(int f=e+1;f<=n-8;f++)
					                                    for(int g=f+1;g<=n-7;g++)
					                                        for(int h=g+1;h<=n-6;h++)
					                                            for(int l=h+1;l<=n-5;l++)
					                                                for(int m=l+1;m<=n-4;m++)
					                                                    for(int o=m+1;o<=n-3;o++)
					                                                        for(int p=o+1;p<=n-2;p++)
					                                                            for(int q=p+1;q<=n-1;q++)
					                                                                for(int r=q+1;r<=n;r++)
						                                                                if(a[i]+a[j]+a[k]+a[t]+a[x]+a[y]+a[z]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]>2*a[r])
							                                                                s+=1;																																																																																																																																				                            
	}
	else
	{
		for(int i=1;i<=n-2;i++)
		{
			w[i]=w[i-1]+i;
		}
		for(int i=1;i<=n-2;i++)
		{
			s+=w[i]*(n-i-1);
		}
	}
	cout<<s;
	return 0;
}

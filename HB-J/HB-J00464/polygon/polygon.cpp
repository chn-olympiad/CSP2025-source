#include <bits/stdc++.h>
using namespace std;
int n;
int arr[5010];
long long cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			for(int k=j+1;k<n;k++)
				if(arr[i]+arr[j]+arr[k]>2*max(arr[i],max(arr[j],arr[k]))) cnt++;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			for(int k=j+1;k<n;k++)
				for(int l=k+1;l<n;l++)
					if(arr[i]+arr[j]+arr[k]+arr[l]>2*max(arr[i],max(arr[j],max(arr[k],arr[l])))) cnt++;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			for(int k=j+1;k<n;k++)
				for(int l=k+1;l<n;l++)
					for(int a=l+1;a<n;a++)
						if(arr[i]+arr[j]+arr[k]+arr[l]+arr[a]>2*max(arr[i],max(arr[j],max(arr[k],max(arr[l],arr[a]))))) cnt++;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			for(int k=j+1;k<n;k++)
				for(int l=k+1;l<n;l++)
					for(int a=l+1;a<n;a++) // 5
						for(int s=a+1;s<n;s++)
							if(arr[i]+arr[j]+arr[k]+arr[l]+arr[a]+arr[s]>2*max(arr[i],max(arr[j],max(arr[k],max(arr[l],max(arr[s],arr[a])))))) cnt++;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			for(int k=j+1;k<n;k++)
				for(int l=k+1;l<n;l++)
					for(int a=l+1;a<n;a++) // 5
						for(int s=a+1;s<n;s++)
							for(int d=s+1;d<n;d++)
								if(arr[i]+arr[j]+arr[k]+arr[l]+arr[a]+arr[s]+arr[d]>2*max(arr[i],max(arr[j],max(arr[k],max(arr[l],max(arr[a],max(arr[s],arr[d]))))))) cnt++;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			for(int k=j+1;k<n;k++)
				for(int l=k+1;l<n;l++)
					for(int a=l+1;a<n;a++) // 5
						for(int s=a+1;s<n;s++)
							for(int d=s+1;d<n;d++)
								for(int f=d+1;f<n;f++)
									if(arr[i]+arr[j]+arr[k]+arr[l]+arr[a]+arr[s]+arr[d]+arr[f]>2*max(arr[i],max(arr[j],max(arr[k],max(arr[l],max(arr[a],max(arr[s],max(arr[d],arr[f])))))))) cnt++;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			for(int k=j+1;k<n;k++)
				for(int l=k+1;l<n;l++)
					for(int a=l+1;a<n;a++)
						for(int s=a+1;s<n;s++)
							for(int d=s+1;d<n;d++)
								for(int f=d+1;f<n;f++)
									for(int g=f+1;g<n;g++) // 10
										if(arr[i]+arr[j]+arr[k]+arr[l]+arr[a]+arr[s]+arr[d]+arr[f]+arr[g]>2*max(arr[i],max(arr[j],max(arr[k],max(arr[l],max(arr[a],max(arr[s],max(arr[d],max(arr[f],arr[g]))))))))) cnt++;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			for(int k=j+1;k<n;k++)
				for(int l=k+1;l<n;l++)
					for(int a=l+1;a<n;a++)
						for(int s=a+1;s<n;s++)
							for(int d=s+1;d<n;d++)
								for(int f=d+1;f<n;f++)
									for(int g=f+1;g<n;g++) // 10
										for(int h=g+1;h<n;h++)
											if(arr[i]+arr[j]+arr[k]+arr[l]+arr[a]+arr[s]+arr[d]+arr[f]+arr[g]+arr[h]>2*max(arr[i],max(arr[j],max(arr[k],max(arr[l],max(arr[a],max(arr[s],max(arr[d],max(arr[f],max(arr[g],arr[h])))))))))) cnt++;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			for(int k=j+1;k<n;k++)
				for(int l=k+1;l<n;l++)
					for(int a=l+1;a<n;a++)
						for(int s=a+1;s<n;s++)
							for(int d=s+1;d<n;d++)
								for(int f=d+1;f<n;f++)
									for(int g=f+1;g<n;g++) // 10
										for(int h=g+1;h<n;h++)
											for(int q=h+1;q<n;q++)
												if(arr[i]+arr[j]+arr[k]+arr[l]+arr[a]+arr[s]+arr[d]+arr[f]+arr[g]+arr[h]+arr[q]>2*max(arr[i],max(arr[j],max(arr[k],max(arr[l],max(arr[a],max(arr[s],max(arr[d],max(arr[f],max(arr[g],max(arr[h],arr[q]))))))))))) cnt++;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			for(int k=j+1;k<n;k++)
				for(int l=k+1;l<n;l++)
					for(int a=l+1;a<n;a++)
						for(int s=a+1;s<n;s++)
							for(int d=s+1;d<n;d++)
								for(int f=d+1;f<n;f++)
									for(int g=f+1;g<n;g++) // 10
										for(int h=g+1;h<n;h++)
											for(int q=h+1;q<n;q++)
												for(int w=q+1;w<n;w++)
													if(arr[i]+arr[j]+arr[k]+arr[l]+arr[a]+arr[s]+arr[d]+arr[f]+arr[g]+arr[h]+arr[q]+arr[w]>2*max(arr[i],max(arr[j],max(arr[k],max(arr[l],max(arr[a],max(arr[s],max(arr[d],max(arr[f],max(arr[g],max(arr[h],max(arr[q],arr[w])))))))))))) cnt++;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			for(int k=j+1;k<n;k++)
				for(int l=k+1;l<n;l++)
					for(int a=l+1;a<n;a++)
						for(int s=a+1;s<n;s++)
							for(int d=s+1;d<n;d++)
								for(int f=d+1;f<n;f++)
									for(int g=f+1;g<n;g++) // 10
										for(int h=g+1;h<n;h++)
											for(int q=h+1;q<n;q++)
												for(int w=q+1;w<n;w++)
													for(int e=w+1;e<n;e++)
														if(arr[i]+arr[j]+arr[k]+arr[l]+arr[a]+arr[s]+arr[d]+arr[f]+arr[g]+arr[h]+arr[q]+arr[w]+arr[e]>2*max(arr[i],max(arr[j],max(arr[k],max(arr[l],max(arr[a],max(arr[s],max(arr[d],max(arr[f],max(arr[g],max(arr[h],max(arr[q],max(arr[w],arr[e]))))))))))))) cnt++;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			for(int k=j+1;k<n;k++)
				for(int l=k+1;l<n;l++)
					for(int a=l+1;a<n;a++)
						for(int s=a+1;s<n;s++)
							for(int d=s+1;d<n;d++)
								for(int f=d+1;f<n;f++)
									for(int g=f+1;g<n;g++) // 10
										for(int h=g+1;h<n;h++)
											for(int q=h+1;q<n;q++)
												for(int w=q+1;w<n;w++)
													for(int e=w+1;e<n;e++)
														for(int r=e+1;r<n;r++)
															if(arr[i]+arr[j]+arr[k]+arr[l]+arr[a]+arr[s]+arr[d]+arr[f]+arr[g]+arr[h]+arr[q]+arr[w]+arr[e]+arr[r]>2*max(arr[i],max(arr[j],max(arr[k],max(arr[l],max(arr[a],max(arr[s],max(arr[d],max(arr[f],max(arr[g],max(arr[h],max(arr[q],max(arr[w],max(arr[e],arr[r])))))))))))))) cnt++;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			for(int k=j+1;k<n;k++)
				for(int l=k+1;l<n;l++)
					for(int a=l+1;a<n;a++)
						for(int s=a+1;s<n;s++)
							for(int d=s+1;d<n;d++)
								for(int f=d+1;f<n;f++)
									for(int g=f+1;g<n;g++)
										for(int h=g+1;h<n;h++)
											for(int q=h+1;q<n;q++)
												for(int w=q+1;w<n;w++)
													for(int e=w+1;e<n;e++)
														for(int r=e+1;r<n;r++)
															for(int t=r+1;t<n;t++) // 15
																if(arr[i]+arr[j]+arr[k]+arr[l]+arr[a]+arr[s]+arr[d]+arr[f]+arr[g]+arr[h]+arr[q]+arr[w]+arr[e]+arr[r]+arr[t]>2*max(arr[i],max(arr[j],max(arr[k],max(arr[l],max(arr[a],max(arr[s],max(arr[d],max(arr[f],max(arr[g],max(arr[h],max(arr[q],max(arr[w],max(arr[e],max(arr[r],arr[t]))))))))))))))) cnt++;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			for(int k=j+1;k<n;k++)
				for(int l=k+1;l<n;l++)
					for(int a=l+1;a<n;a++)
						for(int s=a+1;s<n;s++)
							for(int d=s+1;d<n;d++)
								for(int f=d+1;f<n;f++)
									for(int g=f+1;g<n;g++)
										for(int h=g+1;h<n;h++)
											for(int q=h+1;q<n;q++)
												for(int w=q+1;w<n;w++)
													for(int e=w+1;e<n;e++)
														for(int r=e+1;r<n;r++)
															for(int t=r+1;t<n;t++) // 15
																for(int y=t+1;y<n;y++)
																	if(arr[i]+arr[j]+arr[k]+arr[l]+arr[a]+arr[s]+arr[d]+arr[f]+arr[g]+arr[h]+arr[q]+arr[w]+arr[e]+arr[r]+arr[t]+arr[y]>2*max(arr[i],max(arr[j],max(arr[k],max(arr[l],max(arr[a],max(arr[s],max(arr[d],max(arr[f],max(arr[g],max(arr[h],max(arr[q],max(arr[w],max(arr[e],max(arr[r],max(arr[t],arr[y])))))))))))))))) cnt++;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			for(int k=j+1;k<n;k++)
				for(int l=k+1;l<n;l++)
					for(int a=l+1;a<n;a++)
						for(int s=a+1;s<n;s++)
							for(int d=s+1;d<n;d++)
								for(int f=d+1;f<n;f++)
									for(int g=f+1;g<n;g++)
										for(int h=g+1;h<n;h++)
											for(int q=h+1;q<n;q++)
												for(int w=q+1;w<n;w++)
													for(int e=w+1;e<n;e++)
														for(int r=e+1;r<n;r++)
															for(int t=r+1;t<n;t++) // 15
																for(int y=t+1;y<n;y++)
																	for(int u=y+1;u<n;u++)
																		if(arr[i]+arr[j]+arr[k]+arr[l]+arr[a]+arr[s]+arr[d]+arr[f]+arr[g]+arr[h]+arr[q]+arr[w]+arr[e]+arr[r]+arr[t]+arr[y]+arr[u]>2*max(arr[i],max(arr[j],max(arr[k],max(arr[l],max(arr[a],max(arr[s],max(arr[d],max(arr[f],max(arr[g],max(arr[h],max(arr[q],max(arr[w],max(arr[e],max(arr[r],max(arr[t],max(arr[y],arr[u]))))))))))))))))) cnt++;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			for(int k=j+1;k<n;k++)
				for(int l=k+1;l<n;l++)
					for(int a=l+1;a<n;a++)
						for(int s=a+1;s<n;s++)
							for(int d=s+1;d<n;d++)
								for(int f=d+1;f<n;f++)
									for(int g=f+1;g<n;g++)
										for(int h=g+1;h<n;h++)
											for(int q=h+1;q<n;q++)
												for(int w=q+1;w<n;w++)
													for(int e=w+1;e<n;e++)
														for(int r=e+1;r<n;r++)
															for(int t=r+1;t<n;t++) // 15
																for(int y=t+1;y<n;y++)
																	for(int u=y+1;u<n;u++)
																		for(int o=u+1;o<n;o++)
																			if(arr[i]+arr[j]+arr[k]+arr[l]+arr[a]+arr[s]+arr[d]+arr[f]+arr[g]+arr[h]+arr[q]+arr[w]+arr[e]+arr[r]+arr[t]+arr[y]+arr[u]+arr[o]>2*max(arr[i],max(arr[j],max(arr[k],max(arr[l],max(arr[a],max(arr[s],max(arr[d],max(arr[f],max(arr[g],max(arr[h],max(arr[q],max(arr[w],max(arr[e],max(arr[r],max(arr[t],max(arr[y],max(arr[u],arr[o])))))))))))))))))) cnt++;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			for(int k=j+1;k<n;k++)
				for(int l=k+1;l<n;l++)
					for(int a=l+1;a<n;a++)
						for(int s=a+1;s<n;s++)
							for(int d=s+1;d<n;d++)
								for(int f=d+1;f<n;f++)
									for(int g=f+1;g<n;g++)
										for(int h=g+1;h<n;h++)
											for(int q=h+1;q<n;q++)
												for(int w=q+1;w<n;w++)
													for(int e=w+1;e<n;e++)
														for(int r=e+1;r<n;r++)
															for(int t=r+1;t<n;t++) // 15
																for(int y=t+1;y<n;y++)
																	for(int u=y+1;u<n;u++)
																		for(int o=u+1;o<n;o++)
																			for(int p=o+1;p<n;p++)
																				if(arr[i]+arr[j]+arr[k]+arr[l]+arr[a]+arr[s]+arr[d]+arr[f]+arr[g]+arr[h]+arr[q]+arr[w]+arr[e]+arr[r]+arr[t]+arr[y]+arr[u]+arr[o]+arr[p]>2*max(arr[i],max(arr[j],max(arr[k],max(arr[l],max(arr[a],max(arr[s],max(arr[d],max(arr[f],max(arr[g],max(arr[h],max(arr[q],max(arr[w],max(arr[e],max(arr[r],max(arr[t],max(arr[y],max(arr[u],max(arr[o],arr[p]))))))))))))))))))) cnt++;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			for(int k=j+1;k<n;k++)
				for(int l=k+1;l<n;l++)
					for(int a=l+1;a<n;a++)
						for(int s=a+1;s<n;s++)
							for(int d=s+1;d<n;d++)
								for(int f=d+1;f<n;f++)
									for(int g=f+1;g<n;g++)
										for(int h=g+1;h<n;h++)
											for(int q=h+1;q<n;q++)
												for(int w=q+1;w<n;w++)
													for(int e=w+1;e<n;e++)
														for(int r=e+1;r<n;r++)
															for(int t=r+1;t<n;t++) // 15
																for(int y=t+1;y<n;y++)
																	for(int u=y+1;u<n;u++)
																		for(int o=u+1;o<n;o++)
																			for(int p=o+1;p<n;p++)
																				for(int z=p+1;z<n;z++) // 20
																					if(arr[i]+arr[j]+arr[k]+arr[l]+arr[a]+arr[s]+arr[d]+arr[f]+arr[g]+arr[h]+arr[q]+arr[w]+arr[e]+arr[r]+arr[t]+arr[y]+arr[u]+arr[o]+arr[p]+arr[z]>2*max(arr[i],max(arr[j],max(arr[k],max(arr[l],max(arr[a],max(arr[s],max(arr[d],max(arr[f],max(arr[g],max(arr[h],max(arr[q],max(arr[w],max(arr[e],max(arr[r],max(arr[t],max(arr[y],max(arr[u],max(arr[o],max(arr[p],arr[z])))))))))))))))))))) cnt++;
	cout<<cnt%998244353;
	return 0;
}

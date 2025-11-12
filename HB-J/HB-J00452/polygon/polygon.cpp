#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("input.polygon","r",stdin);
	freopen("output.polygon","w",stdout);
	int n,a[100],x=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n-1;j++){
			for(int k=j+1;k<=n;k++){
				if(a[i]>=a[j]&&a[i]>=a[k]&&a[i]+a[j]+a[k]>2*a[i]){
					x++;
				}else if(a[j]>=a[i]&&a[j]>=a[k]&&a[i]+a[j]+a[k]>2*a[j]){
					x++;
				}else if(a[k]>=a[i]&&a[k]>=a[j]&&a[i]+a[k]+a[j]>2*a[k]){
					x++;
				}
			}
		}
	}
	for(int i=1;i<=n-3;i++){
		for(int j=i+1;j<=n-2;j++){
			for(int k=j+1;k<=n-1;k++){
				for(int l=k+1;l<=n;l++){
					if(a[i]>=a[j]&&a[i]>=a[k]&&a[i]>=a[l]&&a[i]+a[j]+a[k]+a[l]>2*a[i]){
						x++;
					}else if(a[j]>=a[i]&&a[j]>=a[k]&&a[j]>=a[l]&&a[i]+a[j]+a[k]+a[l]>2*a[j]){
						x++;
					}else if(a[k]>=a[i]&&a[k]>=a[j]&&a[k]>=a[l]&&a[i]+a[k]+a[j]+a[l]>2*a[k]){
						x++;
					}else if(a[l]>=a[i]&&a[l]>=a[j]&&a[l]>=a[k]&&a[i]+a[j]+a[k]+a[l]>2*a[l]){
						x++;
					}
				}
			}
		}
	}
	for(int i=1;i<=n-4;i++){
		for(int j=i+1;j<=n-3;j++){
			for(int k=j+1;k<=n-2;k++){
				for(int l=k+1;l<=n-1;l++){
					for(int t=l+1;t<=n;t++){
						if(a[i]>=a[j]&&a[i]>=a[k]&&a[i]>=a[l]&&a[i]>=a[t]&&a[i]+a[j]+a[k]+a[l]+a[t]>2*a[i]){
							x++;
						}else if(a[j]>=a[i]&&a[j]>=a[k]&&a[j]>=a[l]&&a[j]>=a[t]&&a[i]+a[j]+a[k]+a[l]+a[t]>2*a[j]){
							x++;
						}else if(a[k]>=a[i]&&a[k]>=a[j]&&a[k]>=a[l]&&a[k]>=a[t]&&a[i]+a[j]+a[k]+a[l]+a[t]>2*a[k]){
							x++;
						}else if(a[l]>=a[i]&&a[l]>=a[j]&&a[l]>=a[k]&&a[l]>=a[t]&&a[i]+a[j]+a[k]+a[l]+a[t]>2*a[l]){
							x++;
						}else if(a[t]>=a[i]&&a[t]>=a[j]&&a[t]>=a[k]&&a[t]>=a[l]&&a[i]+a[j]+a[k]+a[l]+a[t]>2*a[t]){
							x++;
						}
					}
				}
			}
		}
	}for(int i=1;i<=n-5;i++){
		for(int j=i+1;j<=n-4;j++){
			for(int k=j+1;k<=n-3;k++){
				for(int l=k+1;l<=n-2;l++){
					for(int t=l+1;t<=n-1;t++){
						for(int y=t+1;y<=n;y++){
							if(a[i]>=a[j]&&a[i]>=a[k]&&a[i]>=a[l]&&a[i]>=a[t]&&a[i]>=a[y]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]>2*a[i]){
								x++;
							}else if(a[j]>=a[i]&&a[j]>=a[k]&&a[j]>=a[l]&&a[j]>=a[t]&&a[j]>=a[y]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]>2*a[j]){
								x++;
							}else if(a[k]>=a[i]&&a[k]>=a[j]&&a[k]>=a[l]&&a[k]>=a[t]&&a[k]>=a[y]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]>2*a[k]){
								x++;
							}else if(a[l]>=a[i]&&a[l]>=a[j]&&a[l]>=a[k]&&a[l]>=a[t]&&a[l]>=a[y]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]>2*a[l]){
								x++;
							}else if(a[t]>=a[i]&&a[t]>=a[j]&&a[t]>=a[k]&&a[t]>=a[l]&&a[t]>=a[y]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]>2*a[t]){
								x++;
							}else if(a[y]>=a[i]&&a[y]>=a[j]&&a[y]>=a[k]&&a[y]>=a[l]&&a[y]>=a[t]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]>2*a[y]){
								x++;
							}
						}
					}
				}
			}
		}
	}for(int i=1;i<=n-6;i++){
		for(int j=i+1;j<=n-5;j++){
			for(int k=j+1;k<=n-4;k++){
				for(int l=k+1;l<=n-3;l++){
					for(int t=l+1;t<=n-2;t++){
						for(int y=t+1;y<=n-1;y++){
							for(int h=y+1;h<=n;h++){
								if(a[i]>=a[j]&&a[i]>=a[k]&&a[i]>=a[l]&&a[i]>=a[t]&&a[i]>=a[y]&&a[i]>=a[h]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]>2*a[i]){
									x++;
								}else if(a[j]>=a[i]&&a[j]>=a[k]&&a[j]>=a[l]&&a[j]>=a[t]&&a[j]>=a[y]&&a[j]>=a[h]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]>2*a[j]){
									x++;
								}else if(a[k]>=a[i]&&a[k]>=a[j]&&a[k]>=a[l]&&a[k]>=a[t]&&a[k]>=a[y]&&a[k]>=a[h]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]>2*a[k]){
									x++;
								}else if(a[l]>=a[i]&&a[l]>=a[j]&&a[l]>=a[k]&&a[l]>=a[t]&&a[l]>=a[y]&&a[l]>=a[h]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]>2*a[l]){
									x++;
								}else if(a[t]>=a[i]&&a[t]>=a[j]&&a[t]>=a[k]&&a[t]>=a[l]&&a[t]>=a[y]&&a[t]>=a[h]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]>2*a[t]){
									x++;
								}else if(a[y]>=a[i]&&a[y]>=a[j]&&a[y]>=a[k]&&a[y]>=a[l]&&a[y]>=a[t]&&a[y]>=a[h]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]>2*a[y]){
									x++;
								}else if(a[h]>=a[i]&&a[h]>=a[j]&&a[h]>=a[k]&&a[h]>=a[l]&&a[h]>=a[t]&&a[h]>=a[y]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]>2*a[h]){
									x++;
								}
							}
						}
					}
				}
			}
		}
	}for(int i=1;i<=n-7;i++){
		for(int j=i+1;j<=n-6;j++){
			for(int k=j+1;k<=n-5;k++){
				for(int l=k+1;l<=n-4;l++){
					for(int t=l+1;t<=n-3;t++){
						for(int y=t+1;y<=n-2;y++){
							for(int h=y+1;h<=n-1;h++){
								for(int f=h+1;f<=n;f++){
									if(a[i]>=a[j]&&a[i]>=a[k]&&a[i]>=a[l]&&a[i]>=a[t]&&a[i]>=a[y]&&a[i]>=a[h]&&a[i]>=a[f]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]>2*a[i]){
										x++;
									}else if(a[j]>=a[i]&&a[j]>=a[k]&&a[j]>=a[l]&&a[j]>=a[t]&&a[j]>=a[y]&&a[j]>=a[h]&&a[j]>=a[f]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]>2*a[j]){
										x++;
									}else if(a[k]>=a[i]&&a[k]>=a[j]&&a[k]>=a[l]&&a[k]>=a[t]&&a[k]>=a[y]&&a[k]>=a[h]&&a[k]>=a[f]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]>2*a[k]){
										x++;
									}else if(a[l]>=a[i]&&a[l]>=a[j]&&a[l]>=a[k]&&a[l]>=a[t]&&a[l]>=a[y]&&a[l]>=a[h]&&a[l]>=a[f]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]>2*a[l]){
										x++;
									}else if(a[t]>=a[i]&&a[t]>=a[j]&&a[t]>=a[k]&&a[t]>=a[l]&&a[t]>=a[y]&&a[t]>=a[h]&&a[t]>=a[f]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]>2*a[t]){
										x++;
									}else if(a[y]>=a[i]&&a[y]>=a[j]&&a[y]>=a[k]&&a[y]>=a[l]&&a[y]>=a[t]&&a[y]>=a[h]&&a[y]>=a[f]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]>2*a[y]){
										x++;
									}else if(a[h]>=a[i]&&a[h]>=a[j]&&a[h]>=a[k]&&a[h]>=a[l]&&a[h]>=a[t]&&a[h]>=a[y]&&a[h]>=a[f]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]>2*a[h]){
										x++;
									}else if(a[f]>=a[i]&&a[f]>=a[j]&&a[f]>=a[k]&&a[f]>=a[l]&&a[f]>=a[t]&&a[f]>=a[y]&&a[f]>=a[h]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]>2*a[f]){
										x++;
									}
								}
							}
						}
					}
				}
			}
		}
	}for(int i=1;i<=n-8;i++){
		for(int j=i+1;j<=n-7;j++){
			for(int k=j+1;k<=n-6;k++){
				for(int l=k+1;l<=n-5;l++){
					for(int t=l+1;t<=n-4;t++){
						for(int y=t+1;y<=n-3;y++){
							for(int h=y+1;h<=n-2;h++){
								for(int f=h+1;f<=n-1;f++){
									for(int g=f+1;g<=n;g++){
										if(a[i]>=a[j]&&a[i]>=a[k]&&a[i]>=a[l]&&a[i]>=a[t]&&a[i]>=a[y]&&a[i]>=a[h]&&a[i]>=a[f]&&a[i]>=a[g]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]>2*a[i]){
											x++;
										}else if(a[j]>=a[i]&&a[j]>=a[k]&&a[j]>=a[l]&&a[j]>=a[t]&&a[j]>=a[y]&&a[j]>=a[h]&&a[j]>=a[f]&&a[j]>=a[g]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]>2*a[j]){
											x++;
										}else if(a[k]>=a[i]&&a[k]>=a[j]&&a[k]>=a[l]&&a[k]>=a[t]&&a[k]>=a[y]&&a[k]>=a[h]&&a[k]>=a[f]&&a[k]>=a[g]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]>2*a[k]){
											x++;
										}else if(a[l]>=a[i]&&a[l]>=a[j]&&a[l]>=a[k]&&a[l]>=a[t]&&a[l]>=a[y]&&a[l]>=a[h]&&a[l]>=a[f]&&a[l]>=a[g]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]>2*a[l]){
											x++;
										}else if(a[t]>=a[i]&&a[t]>=a[j]&&a[t]>=a[k]&&a[t]>=a[l]&&a[t]>=a[y]&&a[t]>=a[h]&&a[t]>=a[f]&&a[t]>=a[g]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]>2*a[t]){
											x++;
										}else if(a[y]>=a[i]&&a[y]>=a[j]&&a[y]>=a[k]&&a[y]>=a[l]&&a[y]>=a[t]&&a[y]>=a[h]&&a[y]>=a[f]&&a[y]>=a[g]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]>2*a[y]){
											x++;
										}else if(a[h]>=a[i]&&a[h]>=a[j]&&a[h]>=a[k]&&a[h]>=a[l]&&a[h]>=a[t]&&a[h]>=a[y]&&a[h]>=a[f]&&a[h]>=a[g]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]>2*a[h]){
											x++;
										}else if(a[f]>=a[i]&&a[f]>=a[j]&&a[f]>=a[k]&&a[f]>=a[l]&&a[f]>=a[t]&&a[f]>=a[y]&&a[f]>=a[h]&&a[f]>=a[g]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]>2*a[f]){
											x++;
										}else if(a[g]>=a[i]&&a[g]>=a[j]&&a[g]>=a[k]&&a[g]>=a[l]&&a[g]>=a[t]&&a[g]>=a[y]&&a[g]>=a[h]&&a[g]>=a[f]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]>2*a[g]){
											x++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}for(int i=1;i<=n-9;i++){
		for(int j=i+1;j<=n-8;j++){
			for(int k=j+1;k<=n-7;k++){
				for(int l=k+1;l<=n-6;l++){
					for(int t=l+1;t<=n-5;t++){
						for(int y=t+1;y<=n-4;y++){
							for(int h=y+1;h<=n-3;h++){
								for(int f=h+1;f<=n-2;f++){
									for(int g=f+1;g<=n-1;g++){
										for(int c=g+1;c<=n;c++){
											if(a[i]>=a[j]&&a[i]>=a[k]&&a[i]>=a[l]&&a[i]>=a[t]&&a[i]>=a[y]&&a[i]>=a[h]&&a[i]>=a[f]&&a[i]>=a[g]&&a[i]>=a[c]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]>2*a[i]){
												x++;
											}else if(a[j]>=a[i]&&a[j]>=a[k]&&a[j]>=a[l]&&a[j]>=a[t]&&a[j]>=a[y]&&a[j]>=a[h]&&a[j]>=a[f]&&a[j]>=a[g]&&a[j]>=a[c]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]>2*a[j]){
												x++;
											}else if(a[k]>=a[i]&&a[k]>=a[j]&&a[k]>=a[l]&&a[k]>=a[t]&&a[k]>=a[y]&&a[k]>=a[h]&&a[k]>=a[f]&&a[k]>=a[g]&&a[k]>=a[c]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]>2*a[k]){
												x++;
											}else if(a[l]>=a[i]&&a[l]>=a[j]&&a[l]>=a[k]&&a[l]>=a[t]&&a[l]>=a[y]&&a[l]>=a[h]&&a[l]>=a[f]&&a[l]>=a[g]&&a[l]>=a[c]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]>2*a[l]){
												x++;
											}else if(a[t]>=a[i]&&a[t]>=a[j]&&a[t]>=a[k]&&a[t]>=a[l]&&a[t]>=a[y]&&a[t]>=a[h]&&a[t]>=a[f]&&a[t]>=a[g]&&a[t]>=a[c]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]>2*a[t]){
												x++;
											}else if(a[y]>=a[i]&&a[y]>=a[j]&&a[y]>=a[k]&&a[y]>=a[l]&&a[y]>=a[t]&&a[y]>=a[h]&&a[y]>=a[f]&&a[y]>=a[g]&&a[y]>=a[c]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]>2*a[y]){
												x++;
											}else if(a[h]>=a[i]&&a[h]>=a[j]&&a[h]>=a[k]&&a[h]>=a[l]&&a[h]>=a[t]&&a[h]>=a[y]&&a[h]>=a[f]&&a[h]>=a[g]&&a[h]>=a[c]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]>2*a[h]){
												x++;
											}else if(a[f]>=a[i]&&a[f]>=a[j]&&a[f]>=a[k]&&a[f]>=a[l]&&a[f]>=a[t]&&a[f]>=a[y]&&a[f]>=a[h]&&a[f]>=a[g]&&a[f]>=a[c]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]>2*a[f]){
												x++;
											}else if(a[g]>=a[i]&&a[g]>=a[j]&&a[g]>=a[k]&&a[g]>=a[l]&&a[g]>=a[t]&&a[g]>=a[y]&&a[g]>=a[h]&&a[g]>=a[f]&&a[g]>=a[c]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]>2*a[g]){
												x++;
											}else if(a[c]>=a[i]&&a[c]>=a[j]&&a[c]>=a[k]&&a[c]>=a[l]&&a[c]>=a[t]&&a[c]>=a[y]&&a[c]>=a[h]&&a[c]>=a[f]&&a[c]>=a[g]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]>2*a[c]){
												x++;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}for(int i=1;i<=n-10;i++){
		for(int j=i+1;j<=n-9;j++){
			for(int k=j+1;k<=n-8;k++){
				for(int l=k+1;l<=n-7;l++){
					for(int t=l+1;t<=n-6;t++){
						for(int y=t+1;y<=n-5;y++){
							for(int h=y+1;h<=n-4;h++){
								for(int f=h+1;f<=n-3;f++){
									for(int g=f+1;g<=n-2;g++){
										for(int c=g+1;c<=n-1;c++){
											for(int o=c+1;o<=n;o++){
												if(a[i]>=a[j]&&a[i]>=a[k]&&a[i]>=a[l]&&a[i]>=a[t]&&a[i]>=a[y]&&a[i]>=a[h]&&a[i]>=a[f]&&a[i]>=a[g]&&a[i]>=a[c]&&a[i]>=a[o]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]+a[o]>2*a[i]){
													x++;
												}else if(a[j]>=a[i]&&a[j]>=a[k]&&a[j]>=a[l]&&a[j]>=a[t]&&a[j]>=a[y]&&a[j]>=a[h]&&a[j]>=a[f]&&a[j]>=a[g]&&a[j]>=a[c]&&a[j]>=a[o]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]+a[o]>2*a[j]){
													x++;
												}else if(a[k]>=a[i]&&a[k]>=a[j]&&a[k]>=a[l]&&a[k]>=a[t]&&a[k]>=a[y]&&a[k]>=a[h]&&a[k]>=a[f]&&a[k]>=a[g]&&a[k]>=a[c]&&a[k]>=a[o]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]+a[o]>2*a[k]){
													x++;
												}else if(a[l]>=a[i]&&a[l]>=a[j]&&a[l]>=a[k]&&a[l]>=a[t]&&a[l]>=a[y]&&a[l]>=a[h]&&a[l]>=a[f]&&a[l]>=a[g]&&a[l]>=a[c]&&a[l]>=a[o]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]+a[o]>2*a[l]){
													x++;
												}else if(a[t]>=a[i]&&a[t]>=a[j]&&a[t]>=a[k]&&a[t]>=a[l]&&a[t]>=a[y]&&a[t]>=a[h]&&a[t]>=a[f]&&a[t]>=a[g]&&a[t]>=a[c]&&a[t]>=a[o]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]+a[o]>2*a[t]){
													x++;
												}else if(a[y]>=a[i]&&a[y]>=a[j]&&a[y]>=a[k]&&a[y]>=a[l]&&a[y]>=a[t]&&a[y]>=a[h]&&a[y]>=a[f]&&a[y]>=a[g]&&a[y]>=a[c]&&a[y]>=a[o]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]+a[o]>2*a[y]){
													x++;
												}else if(a[h]>=a[i]&&a[h]>=a[j]&&a[h]>=a[k]&&a[h]>=a[l]&&a[h]>=a[t]&&a[h]>=a[y]&&a[h]>=a[f]&&a[h]>=a[g]&&a[h]>=a[c]&&a[h]>=a[o]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]+a[o]>2*a[h]){
													x++;
												}else if(a[f]>=a[i]&&a[f]>=a[j]&&a[f]>=a[k]&&a[f]>=a[l]&&a[f]>=a[t]&&a[f]>=a[y]&&a[f]>=a[h]&&a[f]>=a[g]&&a[f]>=a[c]&&a[f]>=a[o]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]+a[o]>2*a[f]){
													x++;
												}else if(a[g]>=a[i]&&a[g]>=a[j]&&a[g]>=a[k]&&a[g]>=a[l]&&a[g]>=a[t]&&a[g]>=a[y]&&a[g]>=a[h]&&a[g]>=a[f]&&a[g]>=a[c]&&a[g]>=a[o]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]+a[o]>2*a[g]){
													x++;
												}else if(a[c]>=a[i]&&a[c]>=a[j]&&a[c]>=a[k]&&a[c]>=a[l]&&a[c]>=a[t]&&a[c]>=a[y]&&a[c]>=a[h]&&a[c]>=a[f]&&a[c]>=a[g]&&a[c]>=a[o]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]+a[o]>2*a[c]){
													x++;
												}else if(a[o]>=a[i]&&a[o]>=a[j]&&a[o]>=a[k]&&a[o]>=a[l]&&a[o]>=a[t]&&a[o]>=a[y]&&a[o]>=a[h]&&a[o]>=a[f]&&a[o]>=a[g]&&a[o]>=a[c]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]+a[o]>2*a[o]){
													x++;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}for(int i=1;i<=n-11;i++){
		for(int j=i+1;j<=n-10;j++){
			for(int k=j+1;k<=n-9;k++){
				for(int l=k+1;l<=n-8;l++){
					for(int t=l+1;t<=n-7;t++){
						for(int y=t+1;y<=n-6;y++){
							for(int h=y+1;h<=n-5;h++){
								for(int f=h+1;f<=n-4;f++){
									for(int g=f+1;g<=n-3;g++){
										for(int c=g+1;c<=n-2;c++){
											for(int o=c+1;o<=n-1;o++){
												for(int z=o+1;z<=n;z++){
													if(a[i]>=a[j]&&a[i]>=a[k]&&a[i]>=a[l]&&a[i]>=a[t]&&a[i]>=a[y]&&a[i]>=a[h]&&a[i]>=a[f]&&a[i]>=a[g]&&a[i]>=a[c]&&a[i]>=a[o]&&a[i]>=a[z]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]+a[o]+a[z]>2*a[i]){
														x++;
													}else if(a[j]>=a[i]&&a[j]>=a[k]&&a[j]>=a[l]&&a[j]>=a[t]&&a[j]>=a[y]&&a[j]>=a[h]&&a[j]>=a[f]&&a[j]>=a[g]&&a[j]>=a[c]&&a[j]>=a[o]&&a[j]>=a[z]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]+a[o]+a[z]>2*a[j]){
														x++;
													}else if(a[k]>=a[i]&&a[k]>=a[j]&&a[k]>=a[l]&&a[k]>=a[t]&&a[k]>=a[y]&&a[k]>=a[h]&&a[k]>=a[f]&&a[k]>=a[g]&&a[k]>=a[c]&&a[k]>=a[o]&&a[k]>=a[z]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]+a[o]+a[z]>2*a[k]){
														x++;
													}else if(a[l]>=a[i]&&a[l]>=a[j]&&a[l]>=a[k]&&a[l]>=a[t]&&a[l]>=a[y]&&a[l]>=a[h]&&a[l]>=a[f]&&a[l]>=a[g]&&a[l]>=a[c]&&a[l]>=a[o]&&a[l]>=a[z]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]+a[o]+a[z]>2*a[l]){
														x++;
													}else if(a[t]>=a[i]&&a[t]>=a[j]&&a[t]>=a[k]&&a[t]>=a[l]&&a[t]>=a[y]&&a[t]>=a[h]&&a[t]>=a[f]&&a[t]>=a[g]&&a[t]>=a[c]&&a[t]>=a[o]&&a[t]>=a[z]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]+a[o]+a[z]>2*a[t]){
														x++;
													}else if(a[y]>=a[i]&&a[y]>=a[j]&&a[y]>=a[k]&&a[y]>=a[l]&&a[y]>=a[t]&&a[y]>=a[h]&&a[y]>=a[f]&&a[y]>=a[g]&&a[y]>=a[c]&&a[y]>=a[o]&&a[y]>=a[z]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]+a[o]+a[z]>2*a[y]){
														x++;
													}else if(a[h]>=a[i]&&a[h]>=a[j]&&a[h]>=a[k]&&a[h]>=a[l]&&a[h]>=a[t]&&a[h]>=a[y]&&a[h]>=a[f]&&a[h]>=a[g]&&a[h]>=a[c]&&a[h]>=a[o]&&a[h]>=a[z]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]+a[o]+a[z]>2*a[h]){
														x++;
													}else if(a[f]>=a[i]&&a[f]>=a[j]&&a[f]>=a[k]&&a[f]>=a[l]&&a[f]>=a[t]&&a[f]>=a[y]&&a[f]>=a[h]&&a[f]>=a[g]&&a[f]>=a[c]&&a[f]>=a[o]&&a[f]>=a[z]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]+a[o]+a[z]>2*a[f]){
														x++;
													}else if(a[g]>=a[i]&&a[g]>=a[j]&&a[g]>=a[k]&&a[g]>=a[l]&&a[g]>=a[t]&&a[g]>=a[y]&&a[g]>=a[h]&&a[g]>=a[f]&&a[g]>=a[c]&&a[g]>=a[o]&&a[g]>=a[z]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]+a[o]+a[z]>2*a[g]){
														x++;
													}else if(a[c]>=a[i]&&a[c]>=a[j]&&a[c]>=a[k]&&a[c]>=a[l]&&a[c]>=a[t]&&a[c]>=a[y]&&a[c]>=a[h]&&a[c]>=a[f]&&a[c]>=a[g]&&a[c]>=a[o]&&a[c]>=a[z]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]+a[o]+a[z]>2*a[c]){
														x++;
													}else if(a[o]>=a[i]&&a[o]>=a[j]&&a[o]>=a[k]&&a[o]>=a[l]&&a[o]>=a[t]&&a[o]>=a[y]&&a[o]>=a[h]&&a[o]>=a[f]&&a[o]>=a[g]&&a[o]>=a[c]&&a[o]>=a[z]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]+a[o]+a[z]>2*a[o]){
														x++;
													}else if(a[z]>=a[i]&&a[z]>=a[j]&&a[z]>=a[k]&&a[z]>=a[l]&&a[z]>=a[t]&&a[z]>=a[y]&&a[z]>=a[h]&&a[z]>=a[f]&&a[z]>=a[g]&&a[z]>=a[c]&&a[z]>=a[o]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]+a[o]+a[z]>2*a[z]){
														x++;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}for(int i=1;i<=n-12;i++){
		for(int j=i+1;j<=n-11;j++){
			for(int k=j+1;k<=n-10;k++){
				for(int l=k+1;l<=n-9;l++){
					for(int t=l+1;t<=n-8;t++){
						for(int y=t+1;y<=n-7;y++){
							for(int h=y+1;h<=n-6;h++){
								for(int f=h+1;f<=n-5;f++){
									for(int g=f+1;g<=n-4;g++){
										for(int c=g+1;c<=n-3;c++){
											for(int o=c+1;o<=n-2;o++){
												for(int z=o+1;z<=n-1;z++){
													for(int s=z+1;s<=n;s++){
														if(a[i]>=a[j]&&a[i]>=a[k]&&a[i]>=a[l]&&a[i]>=a[t]&&a[i]>=a[y]&&a[i]>=a[h]&&a[i]>=a[f]&&a[i]>=a[g]&&a[i]>=a[c]&&a[i]>=a[o]&&a[i]>=a[z]&&a[i]>=a[s]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]+a[o]+a[z]+a[s]>2*a[i]){
															x++;
														}else if(a[j]>=a[i]&&a[j]>=a[k]&&a[j]>=a[l]&&a[j]>=a[t]&&a[j]>=a[y]&&a[j]>=a[h]&&a[j]>=a[f]&&a[j]>=a[g]&&a[j]>=a[c]&&a[j]>=a[o]&&a[j]>=a[z]&&a[j]>=a[s]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]+a[o]+a[z]+a[s]>2*a[j]){
															x++;
														}else if(a[k]>=a[i]&&a[k]>=a[j]&&a[k]>=a[l]&&a[k]>=a[t]&&a[k]>=a[y]&&a[k]>=a[h]&&a[k]>=a[f]&&a[k]>=a[g]&&a[k]>=a[c]&&a[k]>=a[o]&&a[k]>=a[z]&&a[k]>=a[s]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]+a[o]+a[z]+a[s]>2*a[k]){
															x++;
														}else if(a[l]>=a[i]&&a[l]>=a[j]&&a[l]>=a[k]&&a[l]>=a[t]&&a[l]>=a[y]&&a[l]>=a[h]&&a[l]>=a[f]&&a[l]>=a[g]&&a[l]>=a[c]&&a[l]>=a[o]&&a[l]>=a[z]&&a[l]>=a[s]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]+a[o]+a[z]+a[s]>2*a[l]){
															x++;
														}else if(a[t]>=a[i]&&a[t]>=a[j]&&a[t]>=a[k]&&a[t]>=a[l]&&a[t]>=a[y]&&a[t]>=a[h]&&a[t]>=a[f]&&a[t]>=a[g]&&a[t]>=a[c]&&a[t]>=a[o]&&a[t]>=a[z]&&a[t]>=a[s]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]+a[o]+a[z]+a[s]>2*a[t]){
															x++;
														}else if(a[y]>=a[i]&&a[y]>=a[j]&&a[y]>=a[k]&&a[y]>=a[l]&&a[y]>=a[t]&&a[y]>=a[h]&&a[y]>=a[f]&&a[y]>=a[g]&&a[y]>=a[c]&&a[y]>=a[o]&&a[y]>=a[z]&&a[y]>=a[s]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]+a[o]+a[z]+a[s]>2*a[y]){
															x++;
														}else if(a[h]>=a[i]&&a[h]>=a[j]&&a[h]>=a[k]&&a[h]>=a[l]&&a[h]>=a[t]&&a[h]>=a[y]&&a[h]>=a[f]&&a[h]>=a[g]&&a[h]>=a[c]&&a[h]>=a[o]&&a[h]>=a[z]&&a[h]>=a[s]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]+a[o]+a[z]+a[s]>2*a[h]){
															x++;
														}else if(a[f]>=a[i]&&a[f]>=a[j]&&a[f]>=a[k]&&a[f]>=a[l]&&a[f]>=a[t]&&a[f]>=a[y]&&a[f]>=a[h]&&a[f]>=a[g]&&a[f]>=a[c]&&a[f]>=a[o]&&a[f]>=a[z]&&a[f]>=a[s]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]+a[o]+a[z]+a[s]>2*a[f]){
															x++;
														}else if(a[g]>=a[i]&&a[g]>=a[j]&&a[g]>=a[k]&&a[g]>=a[l]&&a[g]>=a[t]&&a[g]>=a[y]&&a[g]>=a[h]&&a[g]>=a[f]&&a[g]>=a[c]&&a[g]>=a[o]&&a[g]>=a[z]&&a[g]>=a[s]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]+a[o]+a[z]+a[s]>2*a[g]){
															x++;
														}else if(a[c]>=a[i]&&a[c]>=a[j]&&a[c]>=a[k]&&a[c]>=a[l]&&a[c]>=a[t]&&a[c]>=a[y]&&a[c]>=a[h]&&a[c]>=a[f]&&a[c]>=a[g]&&a[c]>=a[o]&&a[c]>=a[z]&&a[c]>=a[s]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]+a[o]+a[z]+a[s]>2*a[c]){
															x++;
														}else if(a[o]>=a[i]&&a[o]>=a[j]&&a[o]>=a[k]&&a[o]>=a[l]&&a[o]>=a[t]&&a[o]>=a[y]&&a[o]>=a[h]&&a[o]>=a[f]&&a[o]>=a[g]&&a[o]>=a[c]&&a[o]>=a[z]&&a[o]>=a[s]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]+a[o]+a[z]+a[s]>2*a[o]){
															x++;
														}else if(a[z]>=a[i]&&a[z]>=a[j]&&a[z]>=a[k]&&a[z]>=a[l]&&a[z]>=a[t]&&a[z]>=a[y]&&a[z]>=a[h]&&a[z]>=a[f]&&a[z]>=a[g]&&a[z]>=a[c]&&a[z]>=a[o]&&a[z]>=a[s]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]+a[o]+a[z]+a[s]>2*a[z]){
															x++;
														}else if(a[s]>=a[i]&&a[s]>=a[j]&&a[s]>=a[k]&&a[s]>=a[l]&&a[s]>=a[t]&&a[s]>=a[y]&&a[s]>=a[h]&&a[s]>=a[f]&&a[s]>=a[g]&&a[s]>=a[c]&&a[s]>=a[o]&&a[s]>=a[z]&&a[i]+a[j]+a[k]+a[l]+a[t]+a[y]+a[h]+a[f]+a[g]+a[c]+a[o]+a[z]+a[s]>2*a[s]){
															x++;
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}cout<<((x%998)%244)%353;
	return 0;
}

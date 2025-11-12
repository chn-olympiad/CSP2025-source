#include <bits/stdc++.h>
using namespace std;
int a[50005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	sort(a + 1,a + 1 + n);
	int ans = 0;
	for (int i1 = 1;i1 <= n;i1 ++){
		for (int i2 = i1 + 1;i2 <= n;i2 ++){
			for (int i3 = i2 + 1;i3 <= n;i3 ++){
				if ((a[i1] + a[i2] + a[i3]) > (2 * a[i3])){
					ans ++;
				}
			} 
		}
	}
	for (int i1 = 1;i1 <= n;i1 ++){
		for (int i2 = i1 + 1;i2 <= n;i2 ++){
			for (int i3 = i2 + 1;i3 <= n;i3 ++){
				for (int i4 = i3 + 1;i4 <= n;i4 ++){
					if ((a[i1] + a[i2] + a[i3] + a[i4]) > (2 * a[i4])){
						ans ++;
					}
				}
			} 
		}
	}
	for (int i1 = 1;i1 <= n;i1 ++){
		for (int i2 = i1 + 1;i2 <= n;i2 ++){
			for (int i3 = i2 + 1;i3 <= n;i3 ++){
				for (int i4 = i3 + 1;i4 <= n;i4 ++){
					for (int i5 = i4 + 1;i5 <= n;i5 ++){
						if ((a[i1] + a[i2] + a[i3] + a[i4] + a[i5]) > (2 * a[i5])){
							ans ++;
						}
					}
				}
			} 
		}
	}
	for (int i1 = 1;i1 <= n;i1 ++){
		for (int i2 = i1 + 1;i2 <= n;i2 ++){
			for (int i3 = i2 + 1;i3 <= n;i3 ++){
				for (int i4 = i3 + 1;i4 <= n;i4 ++){
					for (int i5 = i4 + 1;i5 <= n;i5 ++){
						for (int i6 = i5 + 1;i6 <= n;i6 ++){
							if ((a[i1] + a[i2] + a[i3] + a[i4] + a[i5] + a[i6]) > (2 * a[i6])){
								ans ++;
							}
						}
					}
				}
			} 
		}
	}
	for (int i1 = 1;i1 <= n;i1 ++){
		for (int i2 = i1 + 1;i2 <= n;i2 ++){
			for (int i3 = i2 + 1;i3 <= n;i3 ++){
				for (int i4 = i3 + 1;i4 <= n;i4 ++){
					for (int i5 = i4 + 1;i5 <= n;i5 ++){
						for (int i6 = i5 + 1;i6 <= n;i6 ++){
							for (int i7 = i6 + 1;i7 <= n;i7 ++){
								if ((a[i1] + a[i2] + a[i3] + a[i4] + a[i5] + a[i6] + a[i7]) > (2 * a[i7])){
									ans ++;
								}
							}
						}
					}
				}
			} 
		}
	}
	for (int i1 = 1;i1 <= n;i1 ++){
		for (int i2 = i1 + 1;i2 <= n;i2 ++){
			for (int i3 = i2 + 1;i3 <= n;i3 ++){
				for (int i4 = i3 + 1;i4 <= n;i4 ++){
					for (int i5 = i4 + 1;i5 <= n;i5 ++){
						for (int i6 = i5 + 1;i6 <= n;i6 ++){
							for (int i7 = i6 + 1;i7 <= n;i7 ++){
								for (int i8 = i7 + 1;i8 <= n;i8 ++){
									if ((a[i1] + a[i2] + a[i3] + a[i4] + a[i5] + a[i6] + a[i7] + a[i8]) > (2 * a[i8])){
										ans ++;
									}
								}
							}
						}
					}
				}
			} 
		}
	}
	for (int i1 = 1;i1 <= n;i1 ++){
		for (int i2 = i1 + 1;i2 <= n;i2 ++){
			for (int i3 = i2 + 1;i3 <= n;i3 ++){
				for (int i4 = i3 + 1;i4 <= n;i4 ++){
					for (int i5 = i4 + 1;i5 <= n;i5 ++){
						for (int i6 = i5 + 1;i6 <= n;i6 ++){
							for (int i7 = i6 + 1;i7 <= n;i7 ++){
								for (int i8 = i7 + 1;i8 <= n;i8 ++){
									for (int i9 = i8 + 1;i9 <= n;i9 ++){
										if ((a[i1] + a[i2] + a[i3] + a[i4] + a[i5] + a[i6] + a[i7] + a[i8] + a[i9]) > (2 * a[i9])){
											ans ++;
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
	for (int i1 = 1;i1 <= n;i1 ++){
		for (int i2 = i1 + 1;i2 <= n;i2 ++){
			for (int i3 = i2 + 1;i3 <= n;i3 ++){
				for (int i4 = i3 + 1;i4 <= n;i4 ++){
					for (int i5 = i4 + 1;i5 <= n;i5 ++){
						for (int i6 = i5 + 1;i6 <= n;i6 ++){
							for (int i7 = i6 + 1;i7 <= n;i7 ++){
								for (int i8 = i7 + 1;i8 <= n;i8 ++){
									for (int i9 = i8 + 1;i9 <= n;i9 ++){
										for (int i10 = i9 + 1;i10 <= n;i10 ++){
											if ((a[i1] + a[i2] + a[i3] + a[i4] + a[i5] + a[i6] + a[i7] + a[i8] + a[i9] + a[i10]) > (2 * a[i10])){
												ans ++;
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
	for (int i1 = 1;i1 <= n;i1 ++){
		for (int i2 = i1 + 1;i2 <= n;i2 ++){
			for (int i3 = i2 + 1;i3 <= n;i3 ++){
				for (int i4 = i3 + 1;i4 <= n;i4 ++){
					for (int i5 = i4 + 1;i5 <= n;i5 ++){
						for (int i6 = i5 + 1;i6 <= n;i6 ++){
							for (int i7 = i6 + 1;i7 <= n;i7 ++){
								for (int i8 = i7 + 1;i8 <= n;i8 ++){
									for (int i9 = i8 + 1;i9 <= n;i9 ++){
										for (int i10 = i9 + 1;i10 <= n;i10 ++){
											for (int i11 = i10 + 1;i11 <= n;i11 ++){
												if ((a[i1] + a[i2] + a[i3] + a[i4] + a[i5] + a[i6] + a[i7] + a[i8] + a[i9] + a[i10] + a[i11]) > (2 * a[i11])){
													ans ++;
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
	for (int i1 = 1;i1 <= n;i1 ++){
		for (int i2 = i1 + 1;i2 <= n;i2 ++){
			for (int i3 = i2 + 1;i3 <= n;i3 ++){
				for (int i4 = i3 + 1;i4 <= n;i4 ++){
					for (int i5 = i4 + 1;i5 <= n;i5 ++){
						for (int i6 = i5 + 1;i6 <= n;i6 ++){
							for (int i7 = i6 + 1;i7 <= n;i7 ++){
								for (int i8 = i7 + 1;i8 <= n;i8 ++){
									for (int i9 = i8 + 1;i9 <= n;i9 ++){
										for (int i10 = i9 + 1;i10 <= n;i10 ++){
											for (int i11 = i10 + 1;i11 <= n;i11 ++){
												for (int i12 = i11 + 1;i12 <= n;i12 ++){
													if ((a[i1] + a[i2] + a[i3] + a[i4] + a[i5] + a[i6] + a[i7] + a[i8] + a[i9] + a[i10] + a[i11] + a[i12]) > (2 * a[i12])){
														ans ++;
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
	for (int i1 = 1;i1 <= n;i1 ++){
		for (int i2 = i1 + 1;i2 <= n;i2 ++){
			for (int i3 = i2 + 1;i3 <= n;i3 ++){
				for (int i4 = i3 + 1;i4 <= n;i4 ++){
					for (int i5 = i4 + 1;i5 <= n;i5 ++){
						for (int i6 = i5 + 1;i6 <= n;i6 ++){
							for (int i7 = i6 + 1;i7 <= n;i7 ++){
								for (int i8 = i7 + 1;i8 <= n;i8 ++){
									for (int i9 = i8 + 1;i9 <= n;i9 ++){
										for (int i10 = i9 + 1;i10 <= n;i10 ++){
											for (int i11 = i10 + 1;i11 <= n;i11 ++){
												for (int i12 = i11 + 1;i12 <= n;i12 ++){
													for (int i13 = i12 + 1;i13 <= n;i13 ++){
														if ((a[i1] + a[i2] + a[i3] + a[i4] + a[i5] + a[i6] + a[i7] + a[i8] + a[i9] + a[i10] + a[i11] + a[i12] + a[i13]) > (2 * a[i13])){
															ans ++;
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
	}
	for (int i1 = 1;i1 <= n;i1 ++){
		for (int i2 = i1 + 1;i2 <= n;i2 ++){
			for (int i3 = i2 + 1;i3 <= n;i3 ++){
				for (int i4 = i3 + 1;i4 <= n;i4 ++){
					for (int i5 = i4 + 1;i5 <= n;i5 ++){
						for (int i6 = i5 + 1;i6 <= n;i6 ++){
							for (int i7 = i6 + 1;i7 <= n;i7 ++){
								for (int i8 = i7 + 1;i8 <= n;i8 ++){
									for (int i9 = i8 + 1;i9 <= n;i9 ++){
										for (int i10 = i9 + 1;i10 <= n;i10 ++){
											for (int i11 = i10 + 1;i11 <= n;i11 ++){
												for (int i12 = i11 + 1;i12 <= n;i12 ++){
													for (int i13 = i12 + 1;i13 <= n;i13 ++){
														for (int i14 = i13 + 1;i14 <= n;i14 ++){
															if ((a[i1] + a[i2] + a[i3] + a[i4] + a[i5] + a[i6] + a[i7] + a[i8] + a[i9] + a[i10] + a[i11] + a[i12] + a[i13] + a[i14]) > (2 * a[i14])){
																ans ++;
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
		}
	}
	for (int i1 = 1;i1 <= n;i1 ++){
		for (int i2 = i1 + 1;i2 <= n;i2 ++){
			for (int i3 = i2 + 1;i3 <= n;i3 ++){
				for (int i4 = i3 + 1;i4 <= n;i4 ++){
					for (int i5 = i4 + 1;i5 <= n;i5 ++){
						for (int i6 = i5 + 1;i6 <= n;i6 ++){
							for (int i7 = i6 + 1;i7 <= n;i7 ++){
								for (int i8 = i7 + 1;i8 <= n;i8 ++){
									for (int i9 = i8 + 1;i9 <= n;i9 ++){
										for (int i10 = i9 + 1;i10 <= n;i10 ++){
											for (int i11 = i10 + 1;i11 <= n;i11 ++){
												for (int i12 = i11 + 1;i12 <= n;i12 ++){
													for (int i13 = i12 + 1;i13 <= n;i13 ++){
														for (int i14 = i13 + 1;i14 <= n;i14 ++){
															for (int i15 = i14 + 1;i15 <= n;i15 ++){
																if ((a[i1] + a[i2] + a[i3] + a[i4] + a[i5] + a[i6] + a[i7] + a[i8] + a[i9] + a[i10] + a[i11] + a[i12] + a[i13] + a[i14] + a[i15]) > (2 * a[i15])){
																	ans ++;
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
			} 
		}
	}
	for (int i1 = 1;i1 <= n;i1 ++){
		for (int i2 = i1 + 1;i2 <= n;i2 ++){
			for (int i3 = i2 + 1;i3 <= n;i3 ++){
				for (int i4 = i3 + 1;i4 <= n;i4 ++){
					for (int i5 = i4 + 1;i5 <= n;i5 ++){
						for (int i6 = i5 + 1;i6 <= n;i6 ++){
							for (int i7 = i6 + 1;i7 <= n;i7 ++){
								for (int i8 = i7 + 1;i8 <= n;i8 ++){
									for (int i9 = i8 + 1;i9 <= n;i9 ++){
										for (int i10 = i9 + 1;i10 <= n;i10 ++){
											for (int i11 = i10 + 1;i11 <= n;i11 ++){
												for (int i12 = i11 + 1;i12 <= n;i12 ++){
													for (int i13 = i12 + 1;i13 <= n;i13 ++){
														for (int i14 = i13 + 1;i14 <= n;i14 ++){
															for (int i15 = i14 + 1;i15 <= n;i15 ++){
																for (int i16 = i15 + 1;i16 <= n;i16 ++){
																	if ((a[i1] + a[i2] + a[i3] + a[i4] + a[i5] + a[i6] + a[i7] + a[i8] + a[i9] + a[i10] + a[i11] + a[i12] + a[i13] + a[i14] + a[i15] + a[i16]) > (2 * a[i16])){
																		ans ++;
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
				}
			} 
		}
	}
	for (int i1 = 1;i1 <= n;i1 ++){
		for (int i2 = i1 + 1;i2 <= n;i2 ++){
			for (int i3 = i2 + 1;i3 <= n;i3 ++){
				for (int i4 = i3 + 1;i4 <= n;i4 ++){
					for (int i5 = i4 + 1;i5 <= n;i5 ++){
						for (int i6 = i5 + 1;i6 <= n;i6 ++){
							for (int i7 = i6 + 1;i7 <= n;i7 ++){
								for (int i8 = i7 + 1;i8 <= n;i8 ++){
									for (int i9 = i8 + 1;i9 <= n;i9 ++){
										for (int i10 = i9 + 1;i10 <= n;i10 ++){
											for (int i11 = i10 + 1;i11 <= n;i11 ++){
												for (int i12 = i11 + 1;i12 <= n;i12 ++){
													for (int i13 = i12 + 1;i13 <= n;i13 ++){
														for (int i14 = i13 + 1;i14 <= n;i14 ++){
															for (int i15 = i14 + 1;i15 <= n;i15 ++){
																for (int i16 = i15 + 1;i16 <= n;i16 ++){
																	for (int i17 = i16 + 1;i17 <= n;i17 ++){
																		if ((a[i1] + a[i2] + a[i3] + a[i4] + a[i5] + a[i6] + a[i7] + a[i8] + a[i9] + a[i10] + a[i11] + a[i12] + a[i13] + a[i14] + a[i15] + a[i16] + a[i17]) > (2 * a[i17])){
																			ans ++;
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
					}
				}
			} 
		}
	}
	for (int i1 = 1;i1 <= n;i1 ++){
		for (int i2 = i1 + 1;i2 <= n;i2 ++){
			for (int i3 = i2 + 1;i3 <= n;i3 ++){
				for (int i4 = i3 + 1;i4 <= n;i4 ++){
					for (int i5 = i4 + 1;i5 <= n;i5 ++){
						for (int i6 = i5 + 1;i6 <= n;i6 ++){
							for (int i7 = i6 + 1;i7 <= n;i7 ++){
								for (int i8 = i7 + 1;i8 <= n;i8 ++){
									for (int i9 = i8 + 1;i9 <= n;i9 ++){
										for (int i10 = i9 + 1;i10 <= n;i10 ++){
											for (int i11 = i10 + 1;i11 <= n;i11 ++){
												for (int i12 = i11 + 1;i12 <= n;i12 ++){
													for (int i13 = i12 + 1;i13 <= n;i13 ++){
														for (int i14 = i13 + 1;i14 <= n;i14 ++){
															for (int i15 = i14 + 1;i15 <= n;i15 ++){
																for (int i16 = i15 + 1;i16 <= n;i16 ++){
																	for (int i17 = i16 + 1;i17 <= n;i17 ++){
																		for (int i18 = i17 + 1;i18 <= n;i18 ++){
																			if ((a[i1] + a[i2] + a[i3] + a[i4] + a[i5] + a[i6] + a[i7] + a[i8] + a[i9] + a[i10] + a[i11] + a[i12] + a[i13] + a[i14] + a[i15] + a[i16] + a[i17] + a[i18]) > (2 * a[i18])){
																				ans ++;
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
						}
					}
				}
			} 
		}
	}
	for (int i1 = 1;i1 <= n;i1 ++){
		for (int i2 = i1 + 1;i2 <= n;i2 ++){
			for (int i3 = i2 + 1;i3 <= n;i3 ++){
				for (int i4 = i3 + 1;i4 <= n;i4 ++){
					for (int i5 = i4 + 1;i5 <= n;i5 ++){
						for (int i6 = i5 + 1;i6 <= n;i6 ++){
							for (int i7 = i6 + 1;i7 <= n;i7 ++){
								for (int i8 = i7 + 1;i8 <= n;i8 ++){
									for (int i9 = i8 + 1;i9 <= n;i9 ++){
										for (int i10 = i9 + 1;i10 <= n;i10 ++){
											for (int i11 = i10 + 1;i11 <= n;i11 ++){
												for (int i12 = i11 + 1;i12 <= n;i12 ++){
													for (int i13 = i12 + 1;i13 <= n;i13 ++){
														for (int i14 = i13 + 1;i14 <= n;i14 ++){
															for (int i15 = i14 + 1;i15 <= n;i15 ++){
																for (int i16 = i15 + 1;i16 <= n;i16 ++){
																	for (int i17 = i16 + 1;i17 <= n;i17 ++){
																		for (int i18 = i17 + 1;i18 <= n;i18 ++){
																			for (int i19 = i18 + 1;i19 <= n;i19 ++){
																				if ((a[i1] + a[i2] + a[i3] + a[i4] + a[i5] + a[i6] + a[i7] + a[i8] + a[i9] + a[i10] + a[i11] + a[i12] + a[i13] + a[i14] + a[i15] + a[i16] + a[i17] + a[i18] + a[i19]) > (2 * a[i19])){
																					ans ++;
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
							}
						}
					}
				}
			} 
		}
	}
	for (int i1 = 1;i1 <= n;i1 ++){
		for (int i2 = i1 + 1;i2 <= n;i2 ++){
			for (int i3 = i2 + 1;i3 <= n;i3 ++){
				for (int i4 = i3 + 1;i4 <= n;i4 ++){
					for (int i5 = i4 + 1;i5 <= n;i5 ++){
						for (int i6 = i5 + 1;i6 <= n;i6 ++){
							for (int i7 = i6 + 1;i7 <= n;i7 ++){
								for (int i8 = i7 + 1;i8 <= n;i8 ++){
									for (int i9 = i8 + 1;i9 <= n;i9 ++){
										for (int i10 = i9 + 1;i10 <= n;i10 ++){
											for (int i11 = i10 + 1;i11 <= n;i11 ++){
												for (int i12 = i11 + 1;i12 <= n;i12 ++){
													for (int i13 = i12 + 1;i13 <= n;i13 ++){
														for (int i14 = i13 + 1;i14 <= n;i14 ++){
															for (int i15 = i14 + 1;i15 <= n;i15 ++){
																for (int i16 = i15 + 1;i16 <= n;i16 ++){
																	for (int i17 = i16 + 1;i17 <= n;i17 ++){
																		for (int i18 = i17 + 1;i18 <= n;i18 ++){
																			for (int i19 = i18 + 1;i19 <= n;i19 ++){
																				for (int i20 = i19 + 1;i20 <= n;i20 ++){
																					if ((a[i1] + a[i2] + a[i3] + a[i4] + a[i5] + a[i6] + a[i7] + a[i8] + a[i9] + a[i10] + a[i11] + a[i12] + a[i13] + a[i14] + a[i15] + a[i16] + a[i17] + a[i18] + a[i19] + a[i20]) > (2 * a[i20])){
																						ans ++;
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
								}
							}
						}
					}
				}
			} 
		}
	}
	cout << ans % 998244353;
	return 0;
}

